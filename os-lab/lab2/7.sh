#!/bin/bash
echo "enter positive integer num"
sum=0
average=0
rev=0
count=0
mod=0
read num
while [ $num -ne 0]
do
mod=$(($num % 10))
sum=$(expr $sum + $mod)
rev=$(expr $rev \* 10)
rev=$(expr $rev + $mod )
num=$(expr $num / 10 )
count=$(expr $count + 1 )
done
average=$(expr $sum / $count )
echo "reverse = $rev"
echo "sum = $sumv"
echo "average = $average"