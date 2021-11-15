#!/bin/bash
echo "enter celsius temp"
read c
f=$c;
f=$(expr $f \* 9)
f=$(expr $f / 5)
f=$(expr $f + 32)
echo "$c = $f"
