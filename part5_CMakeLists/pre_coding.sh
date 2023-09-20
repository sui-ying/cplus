#!/bin/bash

dir1=$1
dir2=$2
echo "./pre_coding.sh $dir1 $dir2"

if [ ! -d "$dir1" ]
then
    mkdir "$dir1"
    if [ ! -d "$dir1/$dir2" ]
    then
        mkdir "$dir1/$dir2"
        cp demo/run.sh $dir1/$dir2/
    else
        # touch $dir1/$dir2/main.cpp
        cp demo/run.sh $dir1/$dir2/
    fi
    
else
    if [ ! -e $dir1/$dir2/run.sh ]
    then
      touch $dir1/$dir2/run.sh
    fi
fi