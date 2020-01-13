#!/bin/bash

for fn in `ls *.cpp`; do 
	g++ $fn
done

