from typing import Any


def callLimit(limit: int):
    """
    Returns a decorator that limits the number of times
    a function can be called.

    This function creates and returns a decorator (`callLimiter`)
    that wraps another function.
    The wrapped function can be executed only up
    to a specified number of times (`limit`).
    Once the limit is reached, further calls will
    print an error message instead of executing the original function.

    Parameters
    ----------
    limit : int
        Maximum number of allowed calls to the decorated function.

    Returns
    -------
    callable
        A decorator that enforces the call limit on the decorated function.
    """
    count = 0

    def callLimiter(function):

        def limit_function(*args: Any, **kwds: Any):
            nonlocal count
            if count < limit:
                count += 1
                return function(*args, **kwds)
            else:
                return print("Error:", function, "call too many times")
        return limit_function
    return callLimiter
