import argparse
import os
from pathlib import Path
import re

def generateKey(path: str) -> None:

    # 1 - Check Given File

    with open(path, "r") as f:
        content = f.read().strip()

        if not re.fullmatch(r"[0-9a-fA-F]{64,}", content):
            raise Exception(
                f"File {path} is invalid (must only contains hexadecimal characters and be at least 64 characters long)"
                )

    # 2 - Generate Key





# def generatePassword(path: str) -> None:


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-g", "--generate", help="Path to Hexadecimal Key")
    parser.add_argument("-k", "--key", help="Path to Key")
    args = parser.parse_args()

    try:
        if args.generate is not None:
            generateKey(args.generate)
        # if args.key is not None:
        #     generatePassword(args.key)
    except Exception as e:
        print("Error:", e)


if __name__ == "__main__":
    main()
