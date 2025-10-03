import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter


def parse_notation(string: str) -> float:
    s = str(string).strip().upper()

    if s.endswith("M"):
        return float(s[:-1]) * 1_000_000
    elif s.endswith("K"):
        return float(s[:-1]) * 1_000
    else:
        return float(s)


def project(df_income: pd.DataFrame, df_life: pd.DataFrame, year: int):

    year = str(year)
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
    plt.xscale("symlog", linthresh=2000)
    plt.gca().xaxis.set_major_formatter(
        FuncFormatter(lambda x, _: f"{x/1e3:.0f}K")
    )
    plt.title(f"{year}")

    plt.show()
