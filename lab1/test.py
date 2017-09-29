import sys
print("Welcome to the Number Guessing Game!")

if len(sys.argv) > 1:
	target = int(sys.argv[1])
else:
	target = input("Please enter the target number")

print("target is {}".format(target))

min = 1
max = 10
def func():
	print("Please enter a number between {} and {}:".format(min, max))

while True:
	func()
	guess = input()
	if guess > max and guess < min:
		print("Please enter a number between $min and $max:")
	elif guess == target:
		print("Bingo")
		break
	elif guess < target:
		min=guess
	elif guess > target:
		max=guess
	else:
		print("error")
