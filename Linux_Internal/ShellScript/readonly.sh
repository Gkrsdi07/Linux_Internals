#!/bin/bash
var=31
readonly var
#var=40
echo "var=>$var"
hello()
{
	echo "HEllo World"
}
readonly hello
#hello()
#{
#echo "Hello World A1"
#}
hello
