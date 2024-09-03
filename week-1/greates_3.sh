echo "enter num 1"
read a
echo "enter num 2"
read b
echo "enter num 3"
read c

if [ $a -ge $b ] && [ $a -ge $c ]; then
    echo "The greatest number is: $a"
elif [ $b -ge $a ] && [ $b -ge $c ]; then
    echo "The greatest number is: $b"
else
    echo "The greatest number is: $c"
fi