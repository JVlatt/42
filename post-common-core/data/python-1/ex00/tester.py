from give_bmi import give_bmi, apply_limit

values = [
    ([2.71, 1.15], [165.3, 38.4]),
    ([3, 0], [0, 164]),
    ([165.3, 10], [165.3, -10]),
    (["slt", 10], [165.3, "slt"])
    ]

for tuple in values:
    print ("Heights:", tuple[0])
    print ("Weights:", tuple[1])
    try:
        bmi = give_bmi(tuple[0], tuple[1])
        print("BMIs :", bmi, type(bmi))
        print(apply_limit(bmi, 26))
        print()

    except ValueError as e:
        print("ValueError:", e)
        print()
