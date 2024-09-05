echo "Enter a number:"
read n
for (( i=2; i<=n; i++ ))
do
    factorial=$((factorial * i))
done
echo "The factorial of $n is: $factorial"
