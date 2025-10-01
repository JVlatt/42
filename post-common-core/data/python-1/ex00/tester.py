from give_bmi import give_bmi, apply_limit


def main():
    """
    Demonstrates the functionality of the give_bmi and apply_limit functions.

    The function tests multiple pairs of height and weight lists, including
    valid and invalid cases, to show how BMI values are calculated and
    how they are compared against a given limit.

    For each test case:
    - Prints the height and weight lists.
    - Attempts to calculate BMI values using give_bmi().
    - Prints the calculated BMI values and their type.
    - Applies apply_limit() with a limit of 26 and prints the results.
    - Catches and prints ValueError exceptions for invalid inputs.

    No parameters or return values.
    """
    values = [
        ([2.71, 1.15], [165.3, 38.4]),
        ([3, 0], [0, 164]),
        ([165.3, 10], [165.3, -10]),
        (["slt", 10], [165.3, "slt"])
        ]

    for tuple in values:
        print("Heights:", tuple[0])
        print("Weights:", tuple[1])
        try:
            bmi = give_bmi(tuple[0], tuple[1])
            print("BMIs :", bmi, type(bmi))
            print(apply_limit(bmi, 26))
            print()

        except ValueError as e:
            print("ValueError:", e)
            print()


if __name__ == "__main__":
    main()
