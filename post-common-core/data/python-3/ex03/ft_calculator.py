import math


class calculator:

    """A Calculator class that implement basic operations"""

    def __init__(self, numbers):
        """Initialize the calculator with a list of floats."""
        if not isinstance(numbers, list):
            raise TypeError("Numbers must be a list.")

        self.numbers = []

        for i, value in enumerate(numbers):
            try:
                self.numbers.append(float(value))
            except (ValueError, TypeError):
                raise ValueError(f"Element at index {i} ('{value}')\
                                  cannot be converted to float.")

    def __add__(self, value) -> None:
        """Add input value to values stored in calculator."""
        if not isinstance(value, (int, float)):
            raise TypeError("Object must be numeric.")

        self.numbers = [num + value for num in self.numbers]
        print(self.numbers)

    def __mul__(self, value) -> None:
        """Multiply input value to values stored in calculator."""
        if not isinstance(value, (int, float)):
            raise TypeError("Object must be numeric.")

        self.numbers = [num * value for num in self.numbers]
        print(self.numbers)

    def __sub__(self, value) -> None:
        """Substract input value to values stored in calculator."""
        if not isinstance(value, (int, float)):
            raise TypeError("Object must be numeric.")

        self.numbers = [num - value for num in self.numbers]
        print(self.numbers)

    def __truediv__(self, value) -> None:
        """Divide input value to values stored in calculator."""
        if not isinstance(value, (int, float)):
            raise TypeError("Object must be numeric.")
        if math.isclose(value, 0.0):
            raise ValueError("Cannot divide by zero")

        self.numbers = [num / value for num in self.numbers]
        print(self.numbers)
