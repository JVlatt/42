import random
import string
from dataclasses import dataclass, field


def generate_id() -> str:
    """
    Generates a random 15-character lowercase identifier.

    Returns
    -------
    str
        A randomly generated string consisting of 15 lowercase ASCII letters.
    """
    return "".join(random.choices(string.ascii_lowercase, k=15))


@dataclass
class Student:
    """
    Represents a student with identifying and status information.

    This dataclass automatically generates a unique ID
    and a login name for each student.
    The login is composed of the student's first initial
    followed by their surname,
    and the ID is a randomly generated 15-character string.

    Attributes
    ----------
    name : str
        The student's first name.
    surname : str
        The student's last name.
    active : bool, optional
        Indicates whether the student is active (default is True).
    login : str
        Automatically generated login name, created after initialization.
    id : str
        Automatically generated unique identifier.
    """

    name: str
    surname: str
    active: bool = True
    login: str = field(init=False)
    id: str = field(init=False, default=generate_id())

    def __post_init__(self):
        self.login = self.name[0] + self.surname
