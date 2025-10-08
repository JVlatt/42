from abc import ABC, abstractmethod


class Character(ABC):
    """Abstract class representing a character with a name and life status."""

    @abstractmethod
    def __init__(self, first_name, is_alive=True):
        """Initialize a character with a first name and a life status."""
        self.first_name = first_name
        self.is_alive = is_alive

    @abstractmethod
    def die(self):
        """Change the life status of the character to False."""
        self.is_alive = False


class Stark(Character):
    """Class representing a member of House Stark."""

    def __init__(self, first_name, is_alive=True):
        """Initialize a Stark with a name and life status."""
        super().__init__(first_name, is_alive)

    def die(self):
        """Set the is_alive attribute of the Stark to False."""
        super().die()
