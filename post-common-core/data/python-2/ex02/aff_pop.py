import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter, MaxNLocator


def parse_notation(string: str) -> float:
    s = str(string).strip().upper()

    if s.endswith("M"):
        return float(s[:-1]) * 1_000_000
    elif s.endswith("K"):
        return float(s[:-1]) * 1_000
    else:
        return float(s)


def compare_pop(table: pd.DataFrame, key1: str, key2: str):
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
    plt.show()
