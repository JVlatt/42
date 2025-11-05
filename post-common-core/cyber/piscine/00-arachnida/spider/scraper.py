from pathlib import Path
from os import access, W_OK
from urllib import request
from urllib.parse import urlparse, urljoin, urldefrag
from selenium import webdriver
from selenium.webdriver.chrome.service import Service as ChromeService
from selenium.webdriver.chrome.options import Options
from selenium.common.exceptions import (
    WebDriverException,
    StaleElementReferenceException,
)
from selenium.webdriver.common.by import By
from scrap_settings import ScrapSettings


RED = "\033[91m"
GREEN = "\033[92m"
YELLOW = "\033[93m"
BLUE = "\033[94m"
RESET = "\033[0m"


# ---------- EXCEPTIONS ---------

class ConnectionErrorException(Exception):
    """Raised when a browser/driver/network error prevents navigation."""
    pass


class ScrapingException(Exception):
    """General scraping error to wrap lower-level exceptions."""
    pass


# ---------- SETUP ---------


def normalize_url(url: str) -> str:
    url, _ = urldefrag(url)
    parsed = urlparse(url)
    path = parsed.path.rstrip('/')
    normalized = f"{parsed.scheme}://{parsed.netloc}{path}"
    return normalized.lower()


def verify_url(driver, url: str, timeout_seconds: int = 10) -> str:
    """
    Navigate driver to url. Returns canonical (final) URL (driver.current_url).
    Raises ConnectionErrorException on navigation failure or obvious redirect-to-root.
    """
    try:
        driver.get(url)
    except WebDriverException as e:
        raise ConnectionErrorException(f"WebDriver failed to navigate to '{url}': {e}") from e

    try:
        ready = driver.execute_script("return document.readyState;")
    except WebDriverException as e:
        raise ConnectionErrorException(f"Failed to check document.readyState for '{url}': {e}") from e

    if ready != "complete":
        raise ConnectionErrorException(f"Page readyState is '{ready}' for '{url}'")

    canonical = driver.current_url
    return canonical


def validate_output_path(path_str: str, default: str = "./datas") -> Path:
    images_dir = Path(path_str) if path_str else Path(default)

    try:
        images_dir.mkdir(parents=True, exist_ok=True)
    except OSError as e:
        raise Exception(f"Cannot create directory '{images_dir}': {e}")

    if not images_dir.is_dir():
        raise Exception(f"'{images_dir}' exists but is not a directory")

    if not access(images_dir, W_OK):
        raise Exception(f"Directory '{images_dir}' is not writable")

    return images_dir


# ---------- DOWNLOAD ---------


def normalize_img_url(url: str) -> str:
    url, _ = urldefrag(url)
    parsed = urlparse(url)
    return f"{parsed.scheme}://{parsed.netloc}{parsed.path}".lower()


def download_image(image_url: str, dest: Path, referer: str) -> None:
    req = request.Request(
        image_url,
        headers={
            "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 Chrome/120 Safari/537.36",
            "Referer": referer
        }
    )
    with request.urlopen(req) as response, open(dest, "wb") as f:
        f.write(response.read())


def scrap_imgs_from_url(
    driver: webdriver.Chrome,
    settings: ScrapSettings,
    downloadcount: int = 0,
    downloaded_imgs: set = set()
) -> int:
    """
    Scrape images from the current page (driver should already be at `url`).
    `path` must be a pathlib.Path pointing to an existing writable directory.
    Returns the updated download count (downloadcount + number_downloaded_here).
    """

    img_html_nodes = driver.find_elements(By.TAG_NAME, "img")
    img_urls = []
    active_count = 0
    skip_count = 0

    print(f"{BLUE}Found {len(img_html_nodes)} Image Nodes ...{RESET}")

    for node in img_html_nodes:
        try:
            img_url = node.get_attribute("src") or node.get_attribute("data-src") or node.get_attribute("data-srcset")
            srcset = node.get_attribute("srcset") or node.get_attribute("data-srcset")
            if srcset:
                srcset_last_element = srcset.split(",")[-1].strip()
                img_url = srcset_last_element.split(" ")[0]
            if img_url:
                img_urls.append(img_url)
        except StaleElementReferenceException:
            continue

    valid_extension = ['.jpeg', '.jpg', '.gif', '.svg', '.bmp', '.png']
    for image_url in img_urls:

        normalized_url = normalize_img_url(image_url)
        if normalized_url in downloaded_imgs:
            skip_count += 1
            continue
        idx = downloadcount + active_count
        try:
            suffix = Path(image_url).suffix.lower()
            if suffix in valid_extension and len(suffix) > 0:
                file_name = settings.output / f"{idx}{suffix}"
            else:
                file_name = settings.output / f"{idx}.jpg"

            download_image(image_url, file_name, settings.root_url)
            downloaded_imgs.add(normalized_url)
        except Exception as e:
            print(f"⚠️ Failed to download image '{image_url}': {e}")
        finally:
            active_count += 1

    print(f"{BLUE}✅ Downloaded {active_count} images in '{driver.current_url}' (skipped {skip_count}){RESET}")
    return downloadcount + active_count

def recursive_scrap(
    driver: webdriver.Chrome,
    settings: ScrapSettings,
    active_url: str,
    activeDepth: int = 0,
    downloadCount: int = 0,
    visited_url: set = set(),
    downloaded_imgs: set = set()
) -> int:

    if active_url in visited_url:
        print(f"{YELLOW}⚠️ '{active_url}' already visited. Skipping...{RESET}")
        return downloadCount

    print(f"{BLUE}✅ Visiting '{active_url}'...{RESET}")
    verify_url(driver, active_url)

    canonical_url = driver.current_url
    if canonical_url in visited_url:
        print(f"{YELLOW}⚠️ '{canonical_url}' already visited (canonical). Skipping...{RESET}")
        return downloadCount

    visited_url.add(canonical_url)

    if activeDepth < settings.limit:

        href_html_nodes = driver.find_elements(By.TAG_NAME, "a")
        valid_hrefs = []

        for node in href_html_nodes:
            try:
                href = node.get_attribute("href")
                if not href:
                    continue
            except StaleElementReferenceException:
                continue

            if not (href.startswith("http://") or href.startswith("https://")):
                continue

            valid_hrefs.append(href)

        print(f"{BLUE}Found {len(valid_hrefs)} hrefs ...{RESET}")
        href_counter = 0
        href_len = len(valid_hrefs)

        for href in valid_hrefs:
            print(f"{BLUE} From '{canonical_url}' going to href ({href_counter}/{href_len})")
            downloadCount = recursive_scrap(
                driver,
                settings,
                href,
                activeDepth + 1,
                downloadCount,
                visited_url,
                downloaded_imgs
            )
            href_counter += 1

    print(f"{GREEN}✅ Scrapping '{canonical_url}' at recursion level {activeDepth}...{RESET}")
    verify_url(driver, canonical_url)
    downloadCount = scrap_imgs_from_url(driver, settings, downloadCount, downloaded_imgs)
    return downloadCount

def print_settings(settings: ScrapSettings) -> None:
    print(f"Scrapping Starting from '{settings.root_url}'")
    print(f"Recursively through [{settings.limit}] levels")
    print(f"Output in '{settings.output}' folder")

def scrapURL(url: str, path: str, levels: int) -> None:
    options = Options()
    options.add_argument("--headless")

    driver = None
    try:
        driver = webdriver.Chrome(service=ChromeService(), options=options)
        try:
            driver.maximize_window()
        except WebDriverException as e:
            print("Warning: maximize_window failed (continuing in headless):", e)

        images_dir = validate_output_path(path)
        settings = ScrapSettings(url, images_dir, levels)
        print_settings(settings)
        total = recursive_scrap(driver, settings, settings.root_url)
        print(f"✅ Successfully downloaded a total of {total} images !")

    except ConnectionErrorException as e:
        raise ConnectionErrorException(f"Connection: {e}")
    except Exception as e:
        raise ScrapingException(e) from e
    finally:
        if driver is not None:
            try:
                driver.quit()
            except Exception as e:
                print("Warning: driver.quit() raised an exception:", e)
