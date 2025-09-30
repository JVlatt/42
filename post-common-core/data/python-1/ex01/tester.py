from array2D import slice_me

family = [
    [1.80, 78.4],
    [2.15, 102.7],
    [2.10, 98.5],
    [1.88, 75.2]
]

print(slice_me(family, 0, 2))
print(slice_me(family, 1, -2))

try:
    slice_me("not a list", 0, 2)
except ValueError as e:
    print("Caught ValueError:", e)

try:
    slice_me([], 0, 1)
except ValueError as e:
    print("Caught ValueError:", e)

try:
    bad_family = [
        [1.70, 65],
        [1.80],
        [1.90, 90]
    ]
    slice_me(bad_family, 0, 2)
except ValueError as e:
    print("Caught ValueError:", e)
