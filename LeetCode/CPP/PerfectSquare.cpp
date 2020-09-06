// LeetCode: https://leetcode.com/problems/valid-perfect-square/

// Author : Vishal Vishwanathan

#include <iostream>
#include <bits/stdc++.h>


class Solution {

public:

    bool isPerfectSquare(int n){
        int left = 2;
        int right = n/2;
        int mid = right+left/2;
        while(left<=right){
            
            if(mid*mid==n)
                return true;
            else if(mid*mid>n)
                right--;
            else 
                left++;

            mid = left+right/2;

        }
        return false;
    }
};

int main(){
    Solution s;
    std::cout<<s.isPerfectSquare(23)<<std::endl;
}
