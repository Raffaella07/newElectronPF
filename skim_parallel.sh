#!/bin/bash
for((i=0;i<10;i=$(($i+1)))); do
screen -A -m -d -S test$i ./exec_skim.sh $i 
done
