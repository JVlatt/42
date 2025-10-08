from S1E7 import Baratheon, Lannister


class King(Baratheon, Lannister):
    """Class representing a King of Westeros."""

    def __init__(self, first_name, is_alive=True):
        super().__init__(first_name, is_alive)

    # Setter for eyes
    def set_eyes(self, value):
        self.eyes = value

    # Getter for eyes
    def get_eyes(self):
        return self.eyes

    # Setter for hairs
    def set_hairs(self, value):
        self.hairs = value

    # Getter for hairs
    def get_hairs(self):
        return self.hairs

    # # With Properties
    # # Getter for eyes
    # @property
    # def eyes(self):
    #     return self._eyes  # internal attribute

    # # Setter for eyes
    # @eyes.setter
    # def eyes(self, value):
    #     self._eyes = value

    # # Getter for hairs
    # @property
    # def hairs(self):
    #     return self._hairs

    # # Setter for hairs
    # @hairs.setter
    # def hairs(self, value):
    #     self._hairs = value
