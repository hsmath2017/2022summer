for num in `seq 4 -1 1`
do
    echo $num little monkeys jumping on the bed
    echo one fell of and bumped his head
done

while true
do
echo "Select an animal (0 to exit):"
    echo "1) Cow"
    echo "2) Donkey"
    echo "3) Dog"
    echo "4) Cat"
    read choice
    case $choice in
        1) echo Moo
        ;;
        2) echo Hee-haw
        ;;
        3) echo Bow wow
        ;;
        4) echo Meow
        ;;
        0) break
        ;;
        *) echo "Please select a valid option"
        ;;
    esac
done
echo "Good bye!"
exit 0