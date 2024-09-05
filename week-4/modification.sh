echo "Enter the filename:"
read filename

mod_time=$(stat -c %y "$filename")

echo "The last modification time of '$filename' is: $mod_time"
