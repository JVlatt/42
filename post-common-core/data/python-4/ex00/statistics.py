from typing import Any
from math import sqrt


def ft_statistics(*args: Any, **kwargs: Any) -> None:

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
        elif arg == "mean":
            print(f"mean : {sum(data) / len(data)}")
        elif arg == "median":
            index = -int(-(len(data) / 2) // 1)
            if len(data) % 2:
                print(f"median : {data[index - 1]}")
            else:
                print(f"median : {(data[index - 1] + data[index]) / 2}")
        elif arg == "quartile":
            qoneindex = -int(-(len(data) / 4) // 1) - 1
            qthreeindex = -int(-((len(data) / 4) * 3) // 1) - 1
            print(f"quartile : [{data[qoneindex]}, {data[qthreeindex]}]")
        elif arg == "std":
            try:
                mean = sum(data) / len(data)
                var = sum((x - mean) ** 2 for x in data) / len(data)
                std = sqrt(var)
                print(f"std : {std}")
            except Exception:
                print("ERROR")
        elif arg == "var":
            mean = sum(data) / len(data)
            var = sum((x - mean) ** 2 for x in data) / len(data)
            print(f"var : {var}")
        else:
            continue
