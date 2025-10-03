import pandas as pd
import os


def load(path: str) -> pd.DataFrame:

    """
    Load a CSV file into a pandas DataFrame.

    Parameters:
        path (str): Path to the CSV file.

    Returns:
        pd.DataFrame: DataFrame containing the CSV data.
    """

    if not os.path.exists(path):
        print(f"❌ Error: File not found at '{path}'")
        return None

    if not path.lower().endswith(".csv"):
        print(f"❌ Error: File '{path}' does not have a .csv extension.")
        return None

    try:
        with open(path, "r", encoding="utf-8") as f:
            first_line = f.readline()
            if "," not in first_line:
                print(f"⚠ Warning: '{path}' does not appear to be a CSV file.")

        dataframe = pd.read_csv(path)
        print("✅ Loading dataset of dimensions", dataframe.shape)
        return dataframe

    except pd.errors.EmptyDataError:
        print(f"❌ Error: File '{path}' is empty.")
    except pd.errors.ParserError:
        print(f"❌ Error: File '{path}' could not be parsed as CSV.")
    except UnicodeDecodeError:
        print(f"❌ Error: Encoding problem reading '{path}'.")
    except Exception as e:
        print(f"❌ Unexpected error: {e}")

    return None
