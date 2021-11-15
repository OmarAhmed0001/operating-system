#!/bin/bash
echo "enter a number: "
read num
echo "enter the power: "
read pow
ans=1
for((i=1;i<=pow;i++))
do
ans=$(( $ans * $num))
done
echo "result = $ans"
