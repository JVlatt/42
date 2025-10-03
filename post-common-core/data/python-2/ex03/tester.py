from sys import argv, exit
from load_csv import load
from projection_life import project


def main():
    """
    Main function to load and print a csv informations.
    """
    argnb = len(argv)
    try:
        assert argnb == 2, "One argument needed"
        year = int(argv[1])
        df_income = load(
            "income_per_person_gdppercapita_ppp_inflation_adjusted.csv"
            )
        df_life = load("life_expectancy_years.csv")
        if df_life is not None and df_income is not None:
            project(df_income, df_life, year)
    except AssertionError as e:
        print("AssertionError:", e)
        exit(1)
    except ValueError as e:
        print("ValueError:", e)
        exit(1)


if __name__ == "__main__":
    main()
