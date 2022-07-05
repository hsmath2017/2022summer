#!/bin/bash
NAMES=("Doc" "Grumpy" "Happy" "Sleepy" "Bashful" "Sneezy" "Dopey")
LENGTH=${#NAMES[@]}
L=${#NAMES}
echo $LENGTH
echo $L
echo $NAMES
echo ${NAMES[0]}
echo ${NAMES[$L-1]}
echo ${NAMES[*]} | xargs -n 1 | sort