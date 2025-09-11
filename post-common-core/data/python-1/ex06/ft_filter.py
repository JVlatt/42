def ft_filter(func=None, iterable=None):

    """filter(function or None, iterable) --> filter object

Return an iterator yielding those items of iterable for which function(item)
is true. If function is None, return the items that are true."""

    if iterable is None:
        raise TypeError("ft_filter expected 2 arguments, got 1")

    if func is None:
        return [item for item in iterable if item]
    else:
        return [item for item in iterable if func(item)]
