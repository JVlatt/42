import sys


def count_characters(text):
    """
    Count the number of uppercase letters, lowercase letters,
    punctuation marks, digits and spaces in the given text.

    Parameters:
        text (str): The text to analyze.

    Returns:
        dict: A dictionary with counts for
        'upper', 'lower', 'punct', 'spaces', 'digits'.
    """

    counts = {
        "uppers": 0,
        "lowers": 0,
        "puncts": 0,
        "spaces": 0,
        "digits": 0
    }

    for char in text:
        if char.isupper():
            counts["uppers"] += 1
        elif char.islower():
            counts["lowers"] += 1
        elif char.isdigit():
            counts["digits"] += 1
        elif char.isspace():
            counts["spaces"] += 1
        elif not char.isalnum() and not char.isspace():
            counts["puncts"] += 1

    return counts


def main():
    """
    Main program: reads input text from command-line argument
    or prompts the user if none is provided, counts character\
    types, and prints de the results.
    """

    try:
        if len(sys.argv) == 1:
            text = input("What is the text to count?\n")
        elif len(sys.argv) == 2:
            text = sys.argv[1]
        else:
            raise AssertionError("more than one argument is provided")

        counts = count_characters(text)
        total_chars = len(text)

        print(f"The text contains {total_chars} characters:")
        print(f"{counts['uppers']} upper letters")
        print(f"{counts['lowers']} lower letters")
        print(f"{counts['puncts']} punctuation marks")
        print(f"{counts['spaces']} spaces")
        print(f"{counts['digits']} digits")

    except AssertionError as e:
        print(f"AssertionError: {e}")


if __name__ == "__main__":
    main()
