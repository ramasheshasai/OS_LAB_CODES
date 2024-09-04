echo "Enter something:"
read input
if [[ $input =~ ^[0-9]+$ ]]; then
    echo "The input is a number."
else
    echo "The input is a string."
fi
