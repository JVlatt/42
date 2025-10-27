from typing import Any
from math import sqrt


def ft_statistics(*args: Any, **kwargs: Any) -> None:

    """
    Displays various statistical measures computed from a
    series of numeric values.

    This function accepts a variable number of numeric arguments (*args)
    and one or more keyword arguments (**kwargs)
    specifying which statistics to display. Supported statistics are:
    - "mean"     : arithmetic mean
    - "median"   : median value
    - "quartile" : first and third quartiles
    - "std"      : standard deviation
    - "var"      : variance

    If the input arguments are not all numeric or an error occurs
    during computation, the function prints "ERROR" instead of a result.

    Parameters
    ----------
    *args : Any
        Numeric values (int, float, or convertible to float) to analyze.
    **kwargs : Any
        Key-value pairs indicating which statistics to compute.
        The values must be one of:
        "mean", "median", "quartile", "std", or "var".

    Returns
    -------
    None
        The function does not return anything;
        it prints results directly to the console.
    """

    request = list(kwargs.values())
    data = None
    if args:
        try:
            data = [float(x) for x in args]
            data.sort()
        except Exception:
            data = None

    for arg in request:
        if data is None:
            print("ERROR")
            continue
        match arg:
            case "mean":
                print(f"mean : {sum(data) / len(data)}")
            case "median":
                index = -int(-(len(data) / 2) // 1)
                if len(data) % 2:
                    print(f"median : {data[index - 1]}")
                else:
                    print(f"median : {(data[index - 1] + data[index]) / 2}")
            case "quartile":
                qoneindex = -int(-(len(data) / 4) // 1) - 1
                qthreeindex = -int(-((len(data) / 4) * 3) // 1) - 1
                print(f"quartile : [{data[qoneindex]}, {data[qthreeindex]}]")
            case "std":
                try:
                    mean = sum(data) / len(data)
                    var = sum((x - mean) ** 2 for x in data) / len(data)
                    std = sqrt(var)
                    print(f"std : {std}")
                except Exception:
                    print("ERROR")
            case "var":
                mean = sum(data) / len(data)
                var = sum((x - mean) ** 2 for x in data) / len(data)
                print(f"var : {var}")
            case _:
                continue
