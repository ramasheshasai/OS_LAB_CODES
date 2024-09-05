echo "Enter a string:"
read str
rev_str=$(echo "$str" | rev)
if [ "$str" == "$rev_str" ]; then
    echo "$str is a palindrome."
else
    echo "$str is not a palindrome."
fi
