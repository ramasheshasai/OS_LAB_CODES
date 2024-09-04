echo "Enter the filename:"
read filename
line_number=1
while IFS= read -r line
do
    word_count=$(echo $line | wc -w)
    char_count=$(echo $line | wc -c)
    echo "Line $line_number: $word_count words, $char_count characters"
    line_number=$((line_number + 1))
done < "$filename"
