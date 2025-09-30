from load_image import ft_load


def test_image_load():
    print("\n--- Test: Valid Image ---")
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


if __name__ == "__main__":
    test_image_load()
    test_file_not_found()
    test_invalid_file()
