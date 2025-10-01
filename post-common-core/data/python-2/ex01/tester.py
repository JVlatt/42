from sys import argv, exit
from load_csv import load
from aff_life import aff

def main():
    """
    Main function to load and print a csv informations.
    """
    argnb = len(argv)
    try:
        assert argnb == 3, "Two arguments needed"
        df = load(argv[1])
        if df is not None:
            aff(df, argv[2])
    except AssertionError as e:
        print("AssertionError:", e)
        exit(1)


if __name__ == "__main__":
    main()
