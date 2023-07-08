#!/bin/bash
echo "Arithmetic Oprations"
read a
read b
c=`expr $a + $b`
echo "Addition of Two Number are :$c"
c=`expr $a - $b`
echo "Subtraction of Two Number are:$c"
c=`expr $a \* $b`
echo "Multiplication of Two Number are:$c"
c=`expr $a / $b`
echo "Division of Two Number are:$c"
c=`expr $a % $b`
echo "Modullo of Two Number are:$c"
