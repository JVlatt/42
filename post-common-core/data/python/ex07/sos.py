import sys

NESTED_MORSE = {
    " ": "/ ",
    "A": ".- ",
    "B": "-... ",
    "C": "-.-. ",
    "D": "-.. ",
    "E": ". ",
    "F": "..-. ",
    "G": "--. ",
    "H": ".... ",
    "I": ".. ",
    "J": ".--- ",
    "K": "-.- ",
    "L": ".-.. ",
    "M": "-- ",
    "N": "-. ",
    "O": "--- ",
    "P": ".--. ",
    "Q": "--.- ",
    "R": ".-. ",
    "S": "... ",
    "T": "- ",
    "U": "..- ",
    "V": "...- ",
    "W": ".-- ",
    "X": "-..- ",
    "Y": "-.-- ",
    "Z": "--.. ",
    "0": "----- ",
    "1": ".---- ",
    "2": "..--- ",
    "3": "...-- ",
    "4": "....- ",
    "5": "..... ",
    "6": "-.... ",
    "7": "--... ",
    "8": "---.. ",
    "9": "----. ",
}


def main():
    """
    Encodes argument into Morse Code and print it.

    Usage:

    sos.py <text>

        text (str): The text to encode.
    """


try:
    if len(sys.argv) != 2:
        raise AssertionError("the arguments are bad")

    text = sys.argv[1]
    result = ""

    for character in text:
        if not character.upper() in NESTED_MORSE:
            raise AssertionError("the arguments are bad")
        else:
            result += NESTED_MORSE[character.upper()]

    print(result)

except AssertionError as e:
    print("AssertionError:", e)
    sys.exit(1)

if __name__ == "__main__":
    main()
