import numpy as np
from PIL import Image


def ft_invert(array: np.ndarray) -> np.ndarray:
    """
    Apply an invert filter to an image.

    For each pixel channel (R, G, B), the value is replaced with
    its complement relative to 255

    Parameters:
        array (np.ndarray): Input image as a NumPy array with shape (H, W, 3).

    Returns:
        np.ndarray: New NumPy array with inverted colors.
    """

    if not isinstance(array, np.ndarray):
        raise ValueError("pixels must be a NumPy array")

    resarray = array.copy()
    resarray = 255 - array

    img = Image.fromarray(resarray.astype('uint8'))
    img.save("invert_filter.png")

    return resarray


def ft_red(array: np.ndarray) -> np.ndarray:
    """
    Apply a red filter to an image.

    Sets the green and blue channels to zero, keeping only the red channel.

    Parameters:
        array (np.ndarray): Input image as a NumPy array with shape (H, W, 3).

    Returns:
        np.ndarray: New NumPy array with red filter applied.
    """

    if not isinstance(array, np.ndarray):
        raise ValueError("pixels must be a NumPy array")

    resarray = array.copy()

    resarray[:, :, 1] = 0
    resarray[:, :, 2] = 0

    img = Image.fromarray(resarray.astype('uint8'))
    img.save("red_filter.png")

    return resarray


def ft_green(array: np.ndarray) -> np.ndarray:
    """
    Apply a green filter to an image.

    Sets the red and blue channels to zero, keeping only the green channel.

    Parameters:
        array (np.ndarray): Input image as a NumPy array with shape (H, W, 3).

    Returns:
        np.ndarray: New NumPy array with green filter applied.
    """

    if not isinstance(array, np.ndarray):
        raise ValueError("pixels must be a NumPy array")

    resarray = array.copy()

    resarray[:, :, 0] = 0
    resarray[:, :, 2] = 0

    img = Image.fromarray(resarray.astype('uint8'))
    img.save("green_filter.png")

    return resarray


def ft_blue(array: np.ndarray) -> np.ndarray:
    """
    Apply a blue filter to an image.

    Sets the red and green channels to zero, keeping only the blue channel.

    Parameters:
        array (np.ndarray): Input image as a NumPy array with shape (H, W, 3).

    Returns:
        np.ndarray: New NumPy array with blue filter applied.
    """

    if not isinstance(array, np.ndarray):
        raise ValueError("pixels must be a NumPy array")

    resarray = array.copy()

    resarray[:, :, 0] = 0
    resarray[:, :, 1] = 0

    img = Image.fromarray(resarray.astype('uint8'))
    img.save("blue_filter.png")

    return resarray


def ft_grey(array: np.ndarray) -> np.ndarray:
    """
    Apply a grayscale filter to an image.

    Converts the image to grayscale using a simple channel division
    since addition and multiplication are not allowed.

    Parameters:
        array (np.ndarray): Input image as a NumPy array with shape (H, W, 3).

    Returns:
        np.ndarray: New NumPy array with grayscale filter applied.
    """

    if not isinstance(array, np.ndarray):
        raise ValueError("pixels must be a NumPy array")

    # resarray = array[:, :, 1] / 3
    # resarray = resarray.astype('uint8')
    # resarray = np.expand_dims(resarray, axis=2)
    # resarray = np.squeeze(resarray)

    weights = np.array([0.299, 0.587, 0.114])
    resarray = np.dot(array[..., :3], weights)

    img = Image.fromarray(resarray.astype('uint8'))
    img.save("gray_filter.png")

    return resarray
