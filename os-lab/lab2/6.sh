#!/bin/bash
echo "enter positive integer num"
sum=0
average=0
num=0
count=0
while [ $count -le 0 ]
do
echo "enter positive integer: "
read int
if [ $int -eq 0 ]
then
count=$(expr $count + 1)
elif [ $int -ge 1 ]
then
num=$(expr $num + 1)
sum=$(expr $sum + $int)
else
echo "erorr"
fi
done
if [ $num -ge 1 ]
then
average=$sum
average=$(expr $average / $num)
echo "average = $average"
else
echo "average = 0"
fi
