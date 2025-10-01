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


if __name__ == "__main__":
    test_image_load_jpg()
    test_image_load_jpeg()
    test_file_not_found()
    test_invalid_file()
