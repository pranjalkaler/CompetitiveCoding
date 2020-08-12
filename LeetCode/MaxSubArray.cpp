// LeetCode Problem : https://leetcode.com/problems/maximum-subarray/
// author: Vishal Vishwanathan


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int max = nums.at(0);
            for(int i=0, x =0 ;i!=nums.size();i++){

                x = std::max(nums.at(i), x+nums.at(i));
                max = std::max(max, x);
            }
            return max;
        }
};

int main() {
    Solution s;
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5,4};
    int max = s.maxSubArray(nums);
    cout<<max<<endl;
}
