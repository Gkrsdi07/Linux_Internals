#!/bin/bash

count=-1

if [ $count -gt 0 ] ; then
	echo "Count is postive"
	printf "My current working directory is \n $PWD \n"
elif [ $count -lt -2 ]
then
	echo "count is less than -2"
else
	echo "count lies between 0 and -1"
fi
