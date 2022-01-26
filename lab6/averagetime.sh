#!/bin/bash

# Thomas Laughridge
# tcl5tu@virginia.edu
# 10/19/21

echo 'Input dictionary and grid files'

read dict # get dictionary file
read grid # get grid file

# Get average run time
RUNNING_TIME=`./a.out $dict $grid | tail -1`
total=$RUNNING_TIME

RUNNING_TIME=`./a.out $dict $grid | tail -1`
total=$((total + RUNNING_TIME))

RUNNING_TIME=`./a.out $dict $grid | tail -1`
total=$((total + RUNNING_TIME))

RUNNING_TIME=`./a.out $dict $grid | tail -1`
total=$((total + RUNNING_TIME))

RUNNING_TIME=`./a.out $dict $grid | tail -1`
total=$((total + RUNNING_TIME))

echo $((total/5))


