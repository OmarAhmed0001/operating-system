#!/bin/bash
echo "enter the number"
read num
f=1
for ((i=2;i<$num;i++))
do
n=$(($num % $i))
if [ $n -eq 0 ]
 then
  if [ $num -ne $i ]
   then
    f=0
  fi
fi
done
if[ $f -eq 1 ]
then
echo "$num is prime"
else
echo "$num is not prime" 
fi
