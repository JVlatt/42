def slice_me(family: list, start: int, end: int) -> list:
    """
    slice_me(family: list, start: int, end: int) -> list

    Slice a 2D list (list of lists) along the first axis (rows) from
    index `start` up to, but not including, index `end`.

    The function also prints the original shape and the new shape
    after slicing, where the shape is expressed as (rows, columns).

    Parameters:
    - family: list of lists, representing a 2D array-like structure.
              All rows must have the same number of columns.
    - start: starting index of the slice (inclusive).
    - end: ending index of the slice (exclusive).

    Returns:
    - list: a new 2D list containing the sliced rows.

    Raises:
    - ValueError: if `family` is not a list, is empty, or if the rows
                  do not all have the same number of columns.
    """

    if not isinstance(family, list):
        raise ValueError("Input is not a list")

    if not family:
        raise ValueError("Input list is empty")

    cols = len(family[0])
    rows = len(family)

    if any(len(row) != cols for row in family):
        raise ValueError("Cols have inconsistent number of rows")

    output = family[start:end]

    print(f"My shape is : ({rows}, {cols})")

    if not output:
        print("My new shape is : (0, 0)")
    else:
        ncols = len(output[0])
        nrows = len(output)
        print(f"My new shape is : ({nrows}, {ncols})")

    return output
