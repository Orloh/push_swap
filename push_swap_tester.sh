#!/bin/bash

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
RESET='\033[0m'

# Configuration
ITERATIONS=$1
SIZE=$2
PROGRAM="./push_swap"
CHECKER="./checker_linux"

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

	#Run push_swap and count lines
	RESULT=$($PROGRAM $ARG | wc -l | tr -d ' ')

	# Run the checker and store result
	CHECK_RESULT=$($PROGRAM $ARG | $CHECKER $ARG)

	if [ "$CHECK_RESULT" = "OK" ]; then
		PRINT_CHECK="${GREEN}OK${RESET}"
	else
		PRINT_CHECK="${RED}KO${RESET}"
	fi

	TOTAL=$((TOTAL + RESULT))
	if [ $RESULT -lt $MIN ]; then MIN=$RESULT; fi
	if [ $RESULT -gt $MAX ]; then MAX=$RESULT; fi

	echo -e "Run $i: $RESULT instructions [$PRINT_CHECK]"
done

AVERAGE=$((TOTAL / ITERATIONS))

echo "----------------------------"
echo "Results for $SIZE numbers:"
echo "Average:	$AVERAGE"
echo "Max:	$MAX"
echo "Min:	$MIN"
