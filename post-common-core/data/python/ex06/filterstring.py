import sys


def main():
    """
    Filter the words in the given sentence that have a
    length strictly greater than a given size
    and print it as a list.

    Usage:

    filterstring.py <text> <length>

        text (str): The text to filter.
        length (int): The minimal length filtered
    """


try:
    if len(sys.argv) != 3:
        raise AssertionError("the arguments are bad")

    text = sys.argv[1]
    count_str = sys.argv[2]

    if not count_str.isdigit():
        raise AssertionError("the arguments are bad")

    count = int(count_str)
    words = text.split()
    for word in words:
        for letter in word:
            if not letter.isalnum():
                raise AssertionError("the arguments are bad")

    result = [word for word in words if (lambda w: len(w) > count)(word)]

    print(result)

except AssertionError as e:
    print("AssertionError:", e)
    sys.exit(1)

if __name__ == "__main__":
    main()
