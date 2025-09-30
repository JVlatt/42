from PIL import Image, UnidentifiedImageError
import numpy as np


def ft_load(path: str) -> list:
    """
    Load an image file and return its pixel data in RGB format.

    This function opens the image at the given path, converts it to RGB mode,
    and returns its pixel values as a NumPy array. It also prints the shape
    of the image (height, width, channels).

    Parameters:
        path (str): Path to the image file.
        Supported formats include JPG and JPEG.

    Returns:
        list: A 3-dimensional list (height x width x 3)
        containing RGB pixel values.

    Raises:
        FileNotFoundError: If the file does not exist at the specified path.
        OSError: If the file cannot be opened as an image.
    """
    try:
        img = Image.open(path).convert("RGB")
    except FileNotFoundError:
        raise FileNotFoundError(f"Error: File not found at path '{path}'.")
    except UnidentifiedImageError:
        raise ValueError(
            f"Error: Unable to open '{path}'. Unsupported or corrupted image."
        )
    except Exception as e:
        raise ValueError(f"Error: An unexpected error occurred: {e}")

    pixels = np.array(img)
    print("The shape of image is:", pixels.shape)

    return pixels
