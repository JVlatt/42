import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.ticker import MultipleLocator


def aff(table: pd.DataFrame, key: str):
    """
    Display the life expectancy data and projection for a given country.

    The function:
      - Verifies that the specified country exists in the DataFrame.
      - Prints the country's data as a sub-table.
      - Converts column names (years) to integers.
      - Converts the row values into a time series indexed by year.
      - Handles missing data by warning the user and dropping NaN values.
      - Plots life expectancy trends over time using Matplotlib.

    Args:
        table (pd.DataFrame):
            DataFrame containing life expectancy data by country and year.
            Must include a 'country' column.
        key (str): Name of the country to display.

    Returns:
        None
    """

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

    plt.plot(series.index, series.values)
    plt.xlabel("Year")
    plt.ylabel("Life Expectancy")
    plt.title(f"{key} Life expectancy Projections")

    plt.gca().xaxis.set_major_locator(MultipleLocator(40))

    plt.show()
