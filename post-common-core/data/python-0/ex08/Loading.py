import time


def ft_tqdm(iterable):
    """Decorate an iterable object, returning an iterator which acts exactly
like the original iterable, but prints a dynamically updating
progressbar every time a value is requested.

Parameters
----------
iterable  : iterable
    Iterable to decorate with a progressbar.

Returns
-------
out  : decorated iterator."""

    try:
        total = len(iterable)
    except TypeError:
        raise ValueError("Iterable must have a length")
    length = 60  # default
    start_time = time.time()

    for i, item in enumerate(iterable, 1):
        elapsed = time.time() - start_time
        rate = i / elapsed if elapsed > 0 else 0
        remaining = (total - i) / rate if rate > 0 else 0

        filled = int(length * i / total)
        bar = "█" * filled
        bar = bar.ljust(length, " ")

        percent = (i / total) * 100
        line = (
            f"{percent:3.0f}%|{bar}| {i}/{total} "
            f"[{int(elapsed//60):02d}:{int(elapsed % 60):02d}"
            f"<{int(remaining//60):02d}:{int(remaining % 60):02d}, "
            f"{rate:0.2f}it/s]"
        )
        print(
            "\r" + line.ljust(len(line) + 7),
            end="",
            flush=True
        )
        yield item
    print("\n")
