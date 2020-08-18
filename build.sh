#!/bin/bash

for fn in `find . -name "*.cpp"`; do 
	echo "Currently compiling $fn"
	g++ $fn
done

count=`find . -name "*.cpp" | wc -l`

echo ""
echo "=============================="
echo "         Build Details        " 
echo "       Compiled $count files  "
echo "=============================="

for fn in `find . -name "*.java"`; do
    echo "Currently compiling $fn"
    javac $fn
done

count_java=`find . -name "*.java" | wc -l`

echo ""
echo "=============================="
echo "   Build Details for Java     " 
echo "   Compiled $count_java files "
echo "=============================="
