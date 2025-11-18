from sys import argv, exit
from PIL import Image, UnidentifiedImageError, ExifTags
from typing import Any
from datetime import datetime
import stat
import os

def timeConvert(atime: float) -> str:
    """
    Convert given absolute time to readable dateTime format.

    Parameters:
        atime(float): absolute time to convert

    Returns:
        Formated string
    """
    dt = atime
    newtime = datetime.fromtimestamp(dt)
    return (f"{newtime.date()} at {newtime.time()}")


def sizeFormat(size: int) -> str:
    """
    Convert given file size to KB.

    Parameters:
        size(int): file size in B

    Returns:
        Converted size string
    """
    newform = format(size/1024, ".2f")
    return newform + " KB"


def ft_print_file_data(data: dict[str, Any]) -> None:
    """
    Print data stored in given dictionnary.

    Parameters:
        data(dict[str,Any]): Dictionnary that store file datas

    Returns:
        None
    """
    for key, val in data.items():
        printstr = ""
        if key != "Separator" and key != "Title":
            printstr += f"{key}: "
        printstr += f"{val}"
        print(printstr)


def ft_get_basic_file_data(filepath: str, data: dict[str, Any])-> None:
    """
    Get and store file basic information in a given dictionnary.

    Parameters:
        filepath(str): Path to file
        data(dict[str, Any]): dictionnary where we store the file datas

    Returns:
        None
    """
    data["Title"] = "=============== FILE DATA ==============="
    data["Filename"] = os.path.basename(filepath)
    data["Directory"] = os.path.dirname(filepath)
    data["Absolute Path"] = os.path.abspath(filepath)
    data["Size"] = sizeFormat(os.path.getsize(filepath))
    data["Last Modified"] = timeConvert(os.path.getmtime(filepath))
    data["Created"] = timeConvert(os.path.getctime(filepath))
    data["File Permission"] = stat.filemode(os.stat(filepath).st_mode)


def ft_get_exif_data(img: Image, data: dict[str, Any]) -> None:
    """
    Get and store image EXIF data in a given dictionnary.

    Parameters:
        img(Image): Image loaded previously with PIL
        data(dict[str, Any]): dictionnary where we store the file datas

    Returns:
        None
    """

    exif_data = img._getexif()
    if exif_data is None:
        data["Separator"] = "\nSorry, image has no exif data."
    else:
        data["Separator"] = "\n=============== EXIF DATA ==============="
        for key, val in exif_data.items():
            if key in ExifTags.TAGS:
                data[ExifTags.TAGS[key]] = val
            else:
                data[key] = val


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
    """
    Program try to load an Image at the specified path.
    then print the file's datas if the file is valid.
    Usage :
        scorpion.py <PathToFile>
    """
    argnb = len(argv)

    if argnb < 2:
        print("One or more argument needed !")

    filepaths = argv[1:]
    for filepath in filepaths:
        try:
            data = {}
            img = ft_load_image(filepath)
            ft_get_basic_file_data(filepath, data)
            ft_get_exif_data(img, data)
            ft_print_file_data(data)
        except Exception as e:
            print(e)


if __name__ == "__main__":
    main()
