import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter, MaxNLocator
from matplotlib.ticker import MultipleLocator


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


def compare_pop(table: pd.DataFrame, key1: str, key2: str):
    """
    Compare the population growth of two countries over time.

    The function:
      - Extracts population data for two specified countries.
      - Parses shorthand numeric values (e.g., '2M', '300K') into floats.
      - Plots population trends from 1800 to 2050 on the same graph.
      - Formats the y-axis in millions (e.g., '20M').
      - Displays a simple legend and auto-scales the plot margins.

    Args:
        table (pd.DataFrame):
            DataFrame containing population data by country and year.
            Must include a 'country' column.
        key1 (str): Name of the first country to compare.
        key2 (str): Name of the second country to compare.

    Returns:
        None
    """

    if key1 not in table['country'].values:
        print(f"❌ Error: Country '{key1}' not found.")
        return
    if key2 not in table['country'].values:
        print(f"❌ Error: Country '{key2}' not found.")
        return

    for key in [key1, key2]:
        country_data = table[table['country'] == key].drop(columns="country")
        years = country_data.columns.astype(int)
        values = [parse_notation(v) for v in country_data.values.flatten()]

        series = pd.Series(values, index=years, dtype="float64").dropna()
        filtered_series = series[(series.index >= 1800) &
                                 (series.index <= 2050)]
        plt.plot(filtered_series.index, filtered_series.values, label=key)

    plt.margins(x=0.1, y=0.1)
    plt.xlabel("Year")
    plt.ylabel("Population")
    plt.gca().yaxis.set_major_locator(MaxNLocator(nbins=3))
    plt.gca().yaxis.set_major_formatter(
        FuncFormatter(lambda x, _: f"{x/1e6:.0f}M")
    )
    plt.title(f"{key1} vs {key2} Population")

    plt.legend()

    plt.gca().xaxis.set_major_locator(MultipleLocator(40))

    plt.show()
