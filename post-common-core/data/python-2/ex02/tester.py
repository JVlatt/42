from sys import argv, exit
from load_csv import load
from aff_pop import compare_pop


def main():
    """
    Main function to load and print a csv informations.
    """
    argnb = len(argv)
    try:
        assert argnb == 4, "Three arguments needed"
        df = load(argv[1])
        if df is not None:
            compare_pop(df, argv[2], argv[3])
    except AssertionError as e:
        print("AssertionError:", e)
        exit(1)


if __name__ == "__main__":
    main()
