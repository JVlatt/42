from ft_calculator import calculator


def main():
    """Program to test the implementation of a calculator
    for vector operations."""
    a = [5, 10, 2]
    b = [2, 4, 3]
    calculator.dotproduct(a, b)
    calculator.add_vec(a, b)


if __name__ == "__main__":
    main()
