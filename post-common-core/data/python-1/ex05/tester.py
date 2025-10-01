from load_image import ft_load
from pimp_image import ft_red, ft_green, ft_blue, ft_invert, ft_grey


def main():
    """
    Main function to apply multiple image filters and save the results.

    Loads an image using `ft_load`, then applies the following filters:
    - Red filter (`ft_red`)
    - Green filter (`ft_green`)
    - Blue filter (`ft_blue`)
    - Invert filter (`ft_invert`)
    - Grayscale filter (`ft_grey`)

    Each filtered image is saved as a separate file.
    Finally, prints the docstring for `ft_invert`
    to demonstrate documentation usage.
    """

    array = ft_load("landscape.jpg")

    ft_red(array)
    ft_green(array)
    ft_blue(array)
    ft_invert(array)
    ft_grey(array)

    print(ft_invert.__doc__)


if __name__ == "__main__":
    main()
