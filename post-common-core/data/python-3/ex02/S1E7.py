# S1E7.py
from S1E9 import Character


class Baratheon(Character):
    """Representing the Baratheon family."""

    def __init__(self, first_name, is_alive=True):
        """Initialize a Baratheon with name and life status."""
        super.__init__(first_name, is_alive)
        self.family_name = "Baratheon"
        self.eyes = "brown"
        self.hairs = "dark"

    def die(self):
        """Mark this Baratheon as dead."""
        self.is_alive = False

    def __str__(self):
        """
        Return a string representation.
        """
        return f"Vector: ('{self.family_name}', '{self.eyes}', '{self.hairs}')"

    def __repr__(self):
        """Same as __str__ so printing/inspection yields a readable string."""
        return self.__str__()

    @staticmethod
    def create_baratheon(first_name, is_alive=True):
        """
        Class method to create a Baratheon instance.
        """
        return __class__(first_name, is_alive)


class Lannister(Character):
    """Representing the Lannister family."""

    def __init__(self, first_name, is_alive=True):
        """Initialize a Lannister with name and life status."""
        super.__init__(first_name, is_alive)
        self.family_name = "Lannister"
        self.eyes = "blue"
        self.hairs = "light"

    def die(self):
        """Mark this Lannister as dead."""
        self.is_alive = False

    def __str__(self):
        """
        Return a string representation.
        """
        return f"Vector: ('{self.family_name}', '{self.eyes}', '{self.hairs}')"

    def __repr__(self):
        """Same as __str__ so printing/inspection yields a readable string."""
        return self.__str__()

    @staticmethod
    def create_lannister(first_name, is_alive=True):
        """
        Class method to create a Lannister instance.
        """
        return __class__(first_name, is_alive)
