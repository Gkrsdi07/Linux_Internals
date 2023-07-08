#!/bin/bash

VEGETATION_NAME="fruits"
FRUIT_NAME="ORANGE"

## -le -eq -gt till now we used
## here we using logical operators
if [ $VEGETATION_NAME = "fruits" ] || [ $FRUIT_NAME = "banana" ]
then
	echo "its a fruit"
else
	echo "Its something else, but not orange"
fi
