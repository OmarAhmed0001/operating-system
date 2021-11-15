#!/bin/bash
echo "enter gross salary"
read s
if [ $s -ge 2000 ]
then
s=$(expr $s / 100)
s=$(expr $s \* 85)
elif [ $s -ge 21000 ]
then
s=$(expr $s / 100)
s=$(expr $s \* 90)
fi
echo "net salary = $s"
