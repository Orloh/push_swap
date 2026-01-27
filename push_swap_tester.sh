#!/bin/bash

# Configuration
ITERATIONS=$1
SIZE=$2
PROGRAM="./push_swap"

if [ "$#" -ne 2 ]; then
	echo "Usage: ./tester.sh [number_of_runs] [stack_size]"
	exit 1
fi

TOTAL=0
MIN=2147483647
MAX=0

echo "Running $ITERATIONS tests with $SIZE numbers..."

for ((i=1; i<=$ITERATIONS; i++))
do
	#Generate random numbers
	ARG=$(seq -10000 10000 | shuf -n $SIZE | tr '\n' ' ')

	#RUN push_swap and count lines
	RESULT=$($PROGRAM $ARG | wc -l | tr -d ' ')

	#Update stats
	TOTAL=$((TOTAL + RESULT))
	if [ $RESULT -lt $MIN ]; then MIN=$RESULT; fi
	if [ $RESULT -gt $MAX ]; then MAX=$RESULT; fi

	echo "Run $i: $RESULT instructions"
done

AVERAGE=$((TOTAL / ITERATIONS))

echo "----------------------------"
echo "Results for $SIZE numbers:"
echo "Average:	$AVERAGE"
echo "Max:	$MAX"
echo "Min:	$MIN"
