#!/bin/bash

for fn in `find . -name "*.cpp"`; do 
	echo "Currently compiling $fn"
	g++ $fn
done

count=`find . -name "*.cpp" | wc -l`

echo ""
echo "=============================="
echo "         Build Details        " 
echo "       Compiled $count files    "
echo "=============================="
