function add
{
if [[ ($1 =~ ^[+-]?[0-9]+$)
     && ($2 =~ ^[+-]?[0-9]+$) ]]
    then 
        echo $(( $1+$2 ))
    else
        echo Error: Arguments must be integers
    fi
}
add