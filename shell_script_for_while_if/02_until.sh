#!/bin/bash


## Executes until the condition is false
#until [ condition ]
#do
#	command1
#	command2
#	commandN
#done

until false
do
	echo "Hi there"
	sleep 1
done

#Try this until false with
# true also
