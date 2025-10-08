class calculator:
    """A Calculator class that implement basic vector operations"""

    @staticmethod
    def dotproduct(V1: list[float], V2: list[float]) -> None:
        """Method to print the dot product of two vectors."""
        print("Dot product is:", sum([(va * vb) for va, vb in zip(V1, V2)]))

    @staticmethod
    def add_vec(V1: list[float], V2: list[float]) -> None:
        """Method to print the sum of two vectors."""
        print("Add Vector is :", [float(va + vb) for va, vb in zip(V1, V2)])

    @staticmethod
    def sous_vec(V1: list[float], V2: list[float]) -> None:
        """Method to print the substraction of two vectors."""
        print("Add Vector is :", [float(va - vb) for va, vb in zip(V1, V2)])
