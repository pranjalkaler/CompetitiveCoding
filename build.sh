#!/bin/bash


errorCountCpp=0
errorCountJava=0
for fn in `find . -name "*.cpp"`; do
    g++ $fn
    if [ $? -eq 0 ]; then
        echo "$fn compiled successfully"
    else
        echo "Errors while compiling $fn"
        errorCountCpp=$((errorCountCpp+1))
    fi
done

count_cpp=`find . -name "*.cpp" | wc -l`

echo ""
echo "======================================================="
echo "                 Build Details for C++                 "
echo "                   Compiled $count_cpp files             "
echo "             $errorCountCpp files failed during build        "
echo "======================================================="

for fn in `find . -name "*.java"`; do
    javac $fn
    if [ $? -eq 0 ]; then
        echo "$fn compiled successfully"
    else
        echo "Errors while compiling $fn"
        errorCountJava=$((errorCountJava+1))
    fi
done

count_java=`find . -name "*.java" | wc -l`

echo ""
echo "======================================================="
echo "                 Build Details for Java                "
echo "                   Compiled $count_java files            "
echo "             $errorCountJava files failed during build        "
echo "======================================================="

if [[ $errorCountCpp -eq 0 ]] && [[ $errorCountJava -eq 0 ]] ; then
    echo "BUILD SUCCESS"
    exit 0
else
    echo "BUILD FAILED"
    exit 1
fi
