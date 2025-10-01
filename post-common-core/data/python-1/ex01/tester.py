from array2D import slice_me


def main():
    """
    Demonstrates the functionality of the slice_me function.

    The function tests slicing on a sample 2D list `family` with different
    start and end indices, and also demonstrates error handling.

    For each test case:
    - Prints the result of slice_me.
    - Catches and prints ValueError exceptions for invalid inputs.

    Test cases include:
    - Valid slicing with normal indices.
    - Slicing with negative indices.
    - Invalid input types (non-list input).
    - Empty list input.
    - Input with inconsistent row lengths.

    No parameters or return values.
    """

    family = [
        [1.80, 78.4],
        [2.15, 102.7],
        [2.10, 98.5],
        [1.88, 75.2]
    ]

    print(slice_me(family, 0, 2))
    print(slice_me(family, 1, -2))

    try:
        slice_me("not a list", 0, 2)
    except ValueError as e:
        print("Caught ValueError:", e)

    try:
        slice_me([], 0, 1)
    except ValueError as e:
        print("Caught ValueError:", e)

    try:
        bad_family = [
            [1.70, 65],
            [1.80],
            [1.90, 90]
        ]
        slice_me(bad_family, 0, 2)
    except ValueError as e:
        print("Caught ValueError:", e)


if __name__ == "__main__":
    main()
