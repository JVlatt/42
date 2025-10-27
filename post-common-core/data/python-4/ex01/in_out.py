def square(x: int | float) -> int | float:
    """Return the square of x."""
    return x * x


def pow(x: int | float) -> int | float:
    """Return x raised to the power of itself."""
    return x ** x


def outer(x: int | float, function) -> object:
    """
    Returns a closure that repeatedly applies a given function to a value.

    This function creates and returns an inner function (`inner`) that,
    each time it is called, applies the specified function
    to the variable `x` and updates its value.
    It also keeps track of how many times the function
    has been applied using a local counter.

    Parameters
    ----------
    x : int | float
        Initial numeric value.
    function : callable
        Function to apply to `x` each time the returned closure is called.

    Returns
    -------
    object
        A closure that applies `function` to `x` on each
        invocation and returns the updated value.
    """
    count = 0

    def inner() -> float:
        nonlocal x, count
        x = function(x)
        count += 1
        return x

    return inner
