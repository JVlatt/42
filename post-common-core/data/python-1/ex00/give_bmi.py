def give_bmi(height: list[int | float],
             weight: list[int | float]) -> list[int | float]:
    """
    give_bmi(height: list[int | float], weight: list[int | float])
    -> list of BMI values

    Calculate the BMI of given parameters list(heights/weight).
    Return a list of BMI values as floats.
    """
    if len(height) != len(weight) or not height:
        raise ValueError(
            "Height and weight lists must be the same non-zero length"
        )

    elif any(not isinstance(h, (float, int)) for h in height):
        raise ValueError("Height must be a float or an integer")

    elif any(h <= 0 for h in height):
        raise ValueError("Height must be positive and non-zero")

    elif any(not isinstance(w, (int, float)) for w in weight):
        raise ValueError("Weight must be a float or an integer")

    elif any(w <= 0 for w in weight):
        raise ValueError("Weight must be positive and non-zero")

    else:
        return [w / (h * h) for h, w in zip(height, weight)]


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    """
    apply_limit(bmi: list[int | float], limit: int) -> list[bool]

    Compare each BMI value in the input list to a given limit.
    Return a list of boolean values where each boolean indicates
    whether the corresponding BMI exceeds the given limit.

    Parameters:
    - bmi: list of BMI values (int or float) to be checked.
    - limit: integer threshold to compare against.

    Returns:
    - list of bool: True if the BMI value is greater than the limit,
    False otherwise.
    """
    if any(b <= 0 for b in bmi):
        raise ValueError("BMI must be positive and non-zero")
    elif any(l < 0 for l in limit):
        raise ValueError("Limit must be positive")
    else:
        return [value > limit for value in bmi]
