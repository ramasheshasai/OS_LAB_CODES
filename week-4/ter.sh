echo "Enter a string:"
read input
length=${#input}
if [ $length -lt 5 ]; then
    echo "The string doesn't have at least 5 characters."
else
    echo "The string has 5 or more characters."
fi
