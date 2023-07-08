#!/bin/bash

count=0

while [ $count -lt 5 ]
do
	echo "hello there"
	sleep 1
	count=$((count+1))
done

#Other form of writing while
#1)....   while [ 1 ] 2) ....  while : 3) ....  while true ...Infinite loop
#in shell also we can write directly 
