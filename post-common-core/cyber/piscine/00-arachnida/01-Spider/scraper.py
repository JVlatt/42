# from bs4 import BeautifulSoup

# def scrapURL(url: str, path: str, levels:int) -> None:
#     try:
#         page = requests.get(url)
#     except requests.exceptions.RequestException as e:
#         raise e
#     soup = BeautifulSoup(page.text, 'html.parser')
#     imgs = soup.find_all('img')

import urllib.request
from selenium import webdriver
from selenium.webdriver.chrome.service import Service as ChromeService
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.common.exceptions import StaleElementReferenceException
from pathlib import Path

def scrapURL(url: str, path: str, levels:int) -> None:
    options = Options()
    options.add_argument("--headless")

    driver = webdriver.Chrome(
        service=ChromeService(),
        options=options
    )

    driver.maximize_window()

    driver.get(url)
    img_html_nodes = driver.find_elements(By.TAG_NAME, "img")
    img_urls = []

    for node in img_html_nodes:
        try:
            img_url = node.get_attribute("src")

            srcset =  node.get_attribute("srcset")

            if srcset:
                srcset_last_element = srcset.split(", ")[-1]
                img_url = srcset_last_element.split(" ")[0]
            if img_url:
                img_urls.append(img_url)
        except StaleElementReferenceException as e:
            continue

    # img_urls = [x for x in img_urls if x.strip()]
    print(img_urls)

    valid_extension = ['.jpeg', '.jpg', '.gif', '.svg', '.bmp', '.png']

    image_name_counter = 0

    for image_url in img_urls:

        print(f"downloading image no. {image_name_counter} ...")
        suffix = Path(image_url).suffix
        if suffix in valid_extension:
            file_name = f"./images/{image_name_counter}{suffix}"
        else:
            file_name = f"./images/{image_name_counter}.jpg"
        urllib.request.urlretrieve(image_url, file_name)
        print (f"images downloaded successfully to {file_name}")
        image_name_counter += 1

    driver.quit()
