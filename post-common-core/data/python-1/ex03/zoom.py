from load_image import ft_load
from PIL import Image, ImageDraw, ImageFont
import numpy as np


def display(pixels: np.ndarray):

    img = np.squeeze(pixels)
    img = Image.fromarray(img.astype('uint8'))

    margin = 40
    new_width = img.width + margin * 2
    new_height = img.height + margin * 2

    background_color = (255, 255, 255)
    padded_image = Image.new("RGB", (new_width, new_height), background_color)
    padded_image.paste(img, (margin, margin))

    draw = ImageDraw.Draw(padded_image)
    x_start = margin
    y_start = padded_image.height - margin
    x_end = x_start + img.width

    bar_width = 1
    draw.line((x_start, margin, x_end, margin),
              fill="black", width=bar_width)  # top
    draw.line((x_start, y_start, x_end, y_start),
              fill="black", width=bar_width)  # bot
    draw.line((x_start, margin, x_start, y_start),
              fill="black", width=bar_width)  # left
    draw.line((x_end, margin, x_end, y_start),
              fill="black", width=bar_width)  # right

    try:
        font = ImageFont.truetype("arial.ttf", size=12)
    except Exception:
        font = ImageFont.load_default()

    num_ticks = int(img.width / 50)
    tick_size = 5
    for i in range(num_ticks):
        tick_x = x_start + i * 50
        tick_y = margin + i * 50

        draw.line((x_start - tick_size, tick_y, x_start, tick_y),
                  fill="black", width=1)  # left
        draw.text((x_start - tick_size - 6, tick_y - 5), str(i * 50),
                  fill="black", font=font, anchor="ra")

        draw.line((tick_x, y_start, tick_x, y_start + tick_size),
                  fill="black", width=1)  # bot
        draw.text((tick_x, y_start + tick_size + 5), str(i * 50),
                  fill="black", font=font, anchor="ma")

    padded_image.show()


def zoom(img: np.ndarray, center: tuple) -> np.ndarray:
    """
    Zoom a 3D image array around a given center with a given size.

    Parameters:
        img (np.ndarray): The original image array (H, W, C).
        center (tuple[int, int]): (y, x) center coordinates for zooming.
        size (int): Size of the square zoom region.

    Returns:
        np.ndarray: Cropped zoomed image with shape (size, size, 1).
    """

    if not isinstance(img, np.ndarray):
        raise ValueError("Image must be a NumPy array.")

    if img.ndim != 3:
        raise ValueError("Image array must be 3-dimensional (H, W, C).")

    if not (isinstance(center, tuple) and len(center) == 2):
        raise ValueError("Center must be a tuple of two integers (y, x).")

    if not all(isinstance(val, int) and val >= 0 for val in center):
        raise ValueError("Center coordinates must be non-negative integers.")

    x, y = center
    half = 400 // 2

    y_start = max(0, y - half)
    y_end = min(img.shape[0], y + half)
    x_start = max(0, x - half)
    x_end = min(img.shape[1], x + half)

    zoomed = img[y_start:y_end, x_start:x_end, 0:1]
    print("New shape after slicing:",
          zoomed.shape, "or", np.squeeze(zoomed).shape)
    return zoomed


if __name__ == "__main__":
    try:
        img = ft_load("animal.jpeg")
        print(img)
        zoom_pxl = zoom(img, (650, 300))
    except Exception as e:
        print(e)
        exit(1)
    print(zoom_pxl)
    display(zoom_pxl)
