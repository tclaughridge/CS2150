#!/bin/bash

# Thomas Laughridge
# tcl5tu@virginia.edu
# 10/28/21

echo 'enter the exponent for counter.cpp:'

read exp

# Exit checker
q='quit'
if [ $exp == $q ]
then
	exit
fi

# Counter
i=0

# Sum run times
while [ $i -lt 5 ]
do
RUNNING_TIME=`./a.out $exp | tail -1`
total=$RUNNING_TIME

# i++
i=$[$i+1]
done

# Total run time
echo $sum

# Average run times
echo $((total/5))