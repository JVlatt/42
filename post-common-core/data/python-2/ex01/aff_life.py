import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

def aff(table: pd.DataFrame, key: str):
    if key not in table['country'].values:
        print(f"❌ Error: Country '{key}' not found.")
        return
    country_data = table[table['country'] == key].drop(columns="country")
    print(country_data)

    years = country_data.columns.astype(int)
    values = country_data.values.flatten()

    series = pd.Series(values, index=years)
    if series.isna().any():
        print(f"⚠️ Warning: {key} has missing values.")

        series = series.dropna()

        # series = series.interpolate(method="linear")


    plt.plot(series.index, series.values)
    plt.xlabel("Year")
    plt.ylabel("Life Expectancy")
    plt.title(f"Life Expectancy in {key}")
    plt.show()
