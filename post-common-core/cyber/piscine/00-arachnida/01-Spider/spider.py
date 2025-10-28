import argparse
from scraper import scrapURL

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("URL", help="Root URL to Scrap")
    parser.add_argument("-r", "--recursive", help="Recursively Scrap URL", action="store_true")
    parser.add_argument("-l", "--levels", help="Level of Recursivity", type=int)
    parser.add_argument("-p", "--path", help="Path to save the Scrapped Files")
    args = parser.parse_args()

    if args.levels is not None and not args.recursive:
        parser.error("argument -l/--levels requires -r/--recursive")

    try:
        scrapURL(args.URL, args.path, args.levels if args.levels is not None else 0)
    except Exception as e:
        print(e)


if __name__ == "__main__":
    main()

