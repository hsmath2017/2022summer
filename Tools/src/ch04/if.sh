var=$1
if [ $(( var%2 )) -eq 0 ]
then
    echo $var is even
else
    echo $var is odd
fi