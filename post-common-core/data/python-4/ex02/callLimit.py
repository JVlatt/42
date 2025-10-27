from typing import Any


def callLimit(limit: int):

    count = 0

    def callLimiter(function):

        def limit_function(*args: Any, **kwds: Any):
            nonlocal count
            if count < limit:
                count += 1
                return function()
            else:
                return print("Error:", function, "call too many times")
        return limit_function
    return callLimiter
