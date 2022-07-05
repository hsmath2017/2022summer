echo ${MY_NAME-Batman}
MY_NAME="Erik"
echo ${MY_NAME-Batman}
MY_AGE=""
echo ${MY_AGE-Undefined}
echo ${MY_AGE:-Undefined}
var=123
echo ${var:="999"}
unset var
echo ${var:="888"}
MY_STRING="this is a long string"
echo ${MY_STRING:10:4}
echo ${#MY_STRING}
tmp=$((3*20+2))
echo $tmp
tmp=3*20+2
echo $tmp
declare -i age 
age=3*20+2
echo $age
v=$(ls -d h*)
echo $v