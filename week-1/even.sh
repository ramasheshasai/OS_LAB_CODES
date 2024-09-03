echo " enter a number " 
read a

if [ $(($a%2)) -eq 0 ]; then
    echo "it is even"
else
    echo " it is oddd"
fi