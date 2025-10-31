from pathlib import Path
from os import access, W_OK
import urllib.request
from selenium import webdriver
from selenium.webdriver.chrome.service import Service as ChromeService
from selenium.webdriver.chrome.options import Options
from selenium.common.exceptions import (
    WebDriverException,
    StaleElementReferenceException,
)
from selenium.webdriver.common.by import By

class ConnectionErrorException(Exception):
    """Raised when a browser/driver/network error prevents navigation."""
    pass


class ScrapingException(Exception):
    """General scraping error to wrap lower-level exceptions."""
    pass


def verify_url(driver, url: str) -> None:
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

    if url not in driver.current_url:
        raise ConnectionErrorException(
            f"Website '{url}' could not be reached (navigated to '{driver.current_url}')"
        )

def validate_output_path(path_str: str, default: str = "./datas") -> Path:
    """
    Validate that the given path is a valid, writable directory.
    Creates the directory if it does not exist.

    Args:
        path_str (str): The user-provided path.
        default (str): Default path if path_str is None or empty.

    Returns:
        Path: A Path object pointing to the valid directory.

    Raises:
        Exception: If the path is invalid, not writable, or cannot be created.
    """
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


def scrap_imgs_from_url(driver: webdriver.Chrome, url: str, path: str, downloadcount = 0) -> None:

    verify_url(driver, url)

    img_html_nodes = driver.find_elements(By.TAG_NAME, "img")
    img_urls = []

    for node in img_html_nodes:
        try:
            img_url = node.get_attribute("src")
            srcset = node.get_attribute("srcset")
            if srcset:
                srcset_last_element = srcset.split(",")[-1].strip()
                img_url = srcset_last_element.split(" ")[0]
            if img_url:
                img_urls.append(img_url)
        except StaleElementReferenceException:
            continue

    valid_extension = ['.jpeg', '.jpg', '.gif', '.svg', '.bmp', '.png']
    image_name_counter = 0
    for image_url in img_urls:
        print(f"downloading image no. {image_name_counter} ...")
        try:
            suffix = Path(image_url).suffix.lower()
            if suffix in valid_extension and len(suffix) > 0:
                file_name = path / f"{image_name_counter}{suffix}"
            else:
                file_name = path / f"{image_name_counter}.jpg"

            urllib.request.urlretrieve(image_url, str(file_name))
            print(f"✅ Image downloaded to {file_name}")
        except Exception as e:
            print(f"⚠️ Failed to download image '{image_url}': {e}")
        finally:
            image_name_counter += 1


# def recursive_scrap(driver: webdriver.Chrome, url: str, path: str,
#                     activeDepth: int = 0, limit: int = 0, downloadcount: int = 0) -> None:


def scrapURL(url: str, path: str, is_recursive: bool, levels: int = 5) -> None:
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
        scrap_imgs_from_url(driver, url, images_dir)

    except ConnectionErrorException as e:
        raise
    except Exception as e:
        raise ScrapingException(e) from e
    finally:
        if driver is not None:
            try:
                driver.quit()
            except Exception as e:
                print("Warning: driver.quit() raised an exception:", e)
