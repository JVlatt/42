from load_image import ft_load


def test_image_load_jpeg():
    print("\n--- Test: Valid Image JPEG ---")
    try:
        pixels = ft_load("animal.jpeg")
        print(pixels)
    except Exception as e:
        print(e)


def test_image_load_jpg():
    print("\n--- Test: Valid Image JPG ---")
    try:
        pixels = ft_load("landscape.jpg")
        print(pixels)
    except Exception as e:
        print(e)


def test_file_not_found():
    print("\n--- Test: File Not Found ---")
    try:
        ft_load("nonexistent.jpg")
    except Exception as e:
        print(e)


def test_invalid_file():
    print("\n--- Test: Invalid Image File ---")
    try:
        ft_load("not_an_image.txt")
    except Exception as e:
        print(e)


def main():
    """
    Run a series of tests for the ft_load function.

    This function executes multiple test cases to verify the behavior of
    ft_load, including:

    - Loading a valid JPG image file.
    - Loading a valid JPEG image file.
    - Attempting to load a non-existent file.
    - Attempting to load an invalid/non-image file.

    For each test, it prints the results or the error message if an exception
    is raised.

    No parameters or return values.
    """
    test_image_load_jpg()
    test_image_load_jpeg()
    test_file_not_found()
    test_invalid_file()


if __name__ == "__main__":
    main()
