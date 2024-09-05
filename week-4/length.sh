if [ $# -eq 0 ]; then
    echo "No string provided. Please provide a string as an argument."
    exit 1
fi
input="$1"
length=${#input}
echo "The length of the string '$input' is: $length"
