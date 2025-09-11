import subprocess

test_cases = [
	["14"],
	["-5"],
	[],
	["0"],
	["Hi!"],
	["13", "5"]
]

for args in test_cases:
	cmd = ["python3", "whatis.py"] + args
	print("Test:", f"{' '.join(cmd)}")

	try:
		result = subprocess.run(cmd, capture_output=True, text=True, check=False)
		if result.stdout:
			print(result.stdout, end='')
		if result.stderr:
			print(result.stderr, end='')
	except Exception as e:
		print("Error running script:", e)
