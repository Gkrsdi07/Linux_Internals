#!/bin/bash

echo "1. List of File\n"
echo "2. No. of Process\n"
echo "3. Today's Date\n"
echo "4. Logged users\n"
echo "5. exit\n"

echo "Enter Your Choice"
read ch
case $ch in
	1)ls;;
	2)ps;;
	3)date;;
	4)who;;
	5)exit;;
	*)echo "Wrong choice, Please /\ Enter right(1 to 5) choice"
esac
