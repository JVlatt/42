from sys import argv, exit
from PIL import Image, UnidentifiedImageError, ExifTags
from typing import Any
from datetime import datetime
import stat
import os

def timeConvert(atime):
    dt = atime
    newtime = datetime.fromtimestamp(dt)
    return (f"{newtime.date()} at {newtime.time()}")


def sizeFormat(size):
    newform = format(size/1024, ".2f")
    return newform + " KB"


def ft_get_basic_file_data(filepath: str, data: dict[str, Any])-> None:
    print("Filename:", os.path.basename(filepath))
    print("Directory:", os.path.dirname(filepath))
    print("Absolute Path:", os.path.abspath(filepath))
    print("Size:", sizeFormat(os.path.getsize(filepath)))
    print("Last Modified:", timeConvert(os.path.getmtime(filepath)))
    print("Created:", timeConvert(os.path.getctime(filepath)))
    print("File Permission:", stat.filemode(os.stat(filepath).st_mode))


def ft_load_image(filepath: str) -> Image:
    """
    Load an image file and return its EXIF data in RGB format.

    This function opens the image at the given path, converts it to RGB mode,
    and returns its pixel values as a NumPy array. It also prints the shape
    of the image (height, width, channels).

    Parameters:
        path (str): Path to the image file.
        Supported formats include JPG and JPEG.

    Returns:
        EXIF Data

    Raises:
        FileNotFoundError: If the file does not exist at the specified os.path.
        OSError: If the file cannot be opened as an image.
    """
    try:
        img = Image.open(filepath)
    except FileNotFoundError:
        raise FileNotFoundError(f"Error: File not found at path '{filepath}'.")
    except UnidentifiedImageError:
        raise ValueError(
            f"Error: Unable to open '{filepath}'. Unsupported or corrupted image."
        )
    except Exception as e:
        raise ValueError(f"Error: An unexpected error occurred: {e}")

    return img


def main():
    argnb = len(argv)

    if argnb < 2:
        print("One or more argument needed !")

    filepaths = argv[1:]
    for filepath in filepaths:
        try:
            data = {}
            ft_load_image(filepath)
            ft_get_basic_file_data(filepath, data)
            print (data)
        except Exception as e:
            print(e)


if __name__ == "__main__":
    main()
