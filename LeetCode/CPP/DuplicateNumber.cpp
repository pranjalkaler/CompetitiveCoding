// Leetcode Problem: https://leetcode.com/problems/find-the-duplicate-number/

// Author: Vishal Vishwanathan

#include <iostream>
#include <bits/stdc++.h>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::set<int> s;
        int n;
        for(auto x: nums){
            if(s.count(x)) {
                n = x;
                break;
            }
            else {
                s.insert(x);
            }
        }
        return n;
    }
};


int main() {
    Solution s;
    vector<int> v = {1,3,3,2,4,5};
    std::cout<<"Answer - "<<s.findDuplicate(v)<<endl;
}
