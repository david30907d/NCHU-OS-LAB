echo "Welcome to the Number Guessing Game!"
echo "Please enter the target number"
if [[ $1 ]]; then
	target=$1
else
	read target
fi
echo "target is $target"
min=1
max=10
func(){
	echo "Please enter a number between $min and $max:"
}
while [[ true ]]; do
	func
	read guess
	if [ "$guess" -gt $max ] && [ "$guess" -lt $min ]; then
		echo "Please enter a number between $min and $max:"
	elif [[ "$guess" -eq "$target" ]]; then
		echo Bingo
		break
	elif [[ "$guess" -lt "$target" ]]; then
		min=$guess
	elif [[ "$guess" -gt "$target" ]]; then
		max=$guess
	else
		echo "error"
	fi
done
