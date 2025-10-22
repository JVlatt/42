def square(x: int | float) -> int | float:
    """Return the square of x."""
    return x * x


def pow(x: int | float) -> int | float:
    """Return x raised to the power of itself."""
    return x ** x

def outer(x: int | float, function) -> object:

    count = 0

    def inner() -> float:
        nonlocal x, count
        x = function(x)
        count += 1
        return x

    return inner
