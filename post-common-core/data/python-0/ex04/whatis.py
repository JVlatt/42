import sys

argnb = len(sys.argv)

try:
	if argnb == 1:
		sys.exit(0)
	assert argnb <= 2, "more than one argument is provided"
	num = int(sys.argv[1])
except AssertionError as e:
	print("AssertionError:", e)
	sys.exit(1)
except ValueError:
	print("AssertionError: argument is not an integer")
	sys.exit(1)

print("I'm Even." if num % 2 == 0 else "I'm Odd.")
