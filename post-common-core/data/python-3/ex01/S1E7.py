# S1E7.py
from S1E9 import Character


class Baratheon(Character):
    """Representing the Baratheon family."""

    def __init__(self, first_name, is_alive=True):
        """Initialize a Baratheon with name and life status."""
        self.first_name = first_name
        self.is_alive = is_alive
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

    @classmethod
    def create_baratheon(cls, first_name, is_alive=True):
        """
        Class method to create a Baratheon instance.
        """
        return cls(first_name, is_alive)


class Lannister(Character):
    """Representing the Lannister family."""

    def __init__(self, first_name, is_alive=True):
        """Initialize a Lannister with name and life status."""
        self.first_name = first_name
        self.is_alive = is_alive
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

    @classmethod
    def create_lannister(cls, first_name, is_alive=True):
        """
        Class method to create a Lannister instance.
        """
        return cls(first_name, is_alive)
