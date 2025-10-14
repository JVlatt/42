import pandas as pd
import matplotlib.pyplot as plt
from sys import exit
from load_csv import load


def parse_notation(string: str) -> float:
    """
    Convert a string containing shorthand numeric notation (e.g., '2.5K', '3M')
    into a float value.

    Args:
        string (str): The numeric string to convert.

    Returns:
        float: The numeric value represented by the input string.
    """

    s = str(string).strip().upper()

    if s.endswith("M"):
        return float(s[:-1]) * 1_000_000
    elif s.endswith("K"):
        return float(s[:-1]) * 1_000
    else:
        return float(s)


def project(df_income: pd.DataFrame, df_life: pd.DataFrame):
    """
    Merge GDP and life expectancy data for a given year and
    display their relationship using a scatter plot.

    The function:
      - Merges two DataFrames (`df_income`, `df_life`) on the 'country' column.
      - Plots life expectancy vs GDP using a symmetric logarithmic x-scale.
      - Customizes tick marks and labels on the x-axis.
      - Displays coordinates dynamically when hovering over the plot.

    Args:
        df_income (pd.DataFrame): DataFrame containing GDP per capita data.
        df_life (pd.DataFrame): DataFrame containing life expectancy data.

    Returns:
        None
    """

    year = "1900"
    if year not in df_income.columns or year not in df_life.columns:
        print(f"❌ Year {year} not found in both DataFrames.")
        return None

    merged_df = pd.merge(
        df_income[['country', year]],
        df_life[['country', year]],
        on="country",
        suffixes=('_income', '_life')
    )

    plt.figure(figsize=(8, 6))
    plt.scatter(
        merged_df[f"{year}_income"],
        merged_df[f"{year}_life"],
        color="#2c66b8"
    )

    plt.xlabel("Gross domestic product")
    plt.ylabel("Life Expectancy")
    plt.xscale("symlog", linthresh=500)

    ticks = list(range(300, 1000, 100)) + list(range(1000, 10001, 1000))
    plt.gca().set_xticks(ticks)

    labels = []
    for t in ticks:
        if t in (300, 1000, 10000):
            if t >= 1000:
                labels.append(f"{t//1000}K")
            else:
                labels.append(str(t))
        else:
            labels.append("")

    plt.gca().set_xticklabels(labels)

    plt.title(f"{year}")

    plt.gca().format_coord = lambda x, y: f"x = {x:.0f}, y = {y:.2f}"
    plt.show()


def main():
    """
    Main function to load and print a combined-csv informations.
    """
    try:
        df_income = load(
            "income_per_person_gdppercapita_ppp_inflation_adjusted.csv"
            )
        df_life = load("life_expectancy_years.csv")
        if df_life is not None and df_income is not None:
            project(df_income, df_life)
    except AssertionError as e:
        print("AssertionError:", e)
        exit(1)
    except ValueError as e:
        print("ValueError:", e)
        exit(1)


if __name__ == "__main__":
    main()
