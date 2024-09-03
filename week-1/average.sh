echo "Enter the number of elements:"
read n
sum=0
for (( i=1; i<=n; i++ ))
do
    echo "Enter number $i:"
    read num
    sum=$((sum + num))
done
ave=$((sum / n))
echo "The average of the $n numbers is: $ave"