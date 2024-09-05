for i in {1..3}
do
    echo "Displaying running processes - Attempt $i:"
    ps aux
    sleep 30
done

echo "Process monitoring completed."
