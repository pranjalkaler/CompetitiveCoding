// LeetCode - https://leetcode.com/problems/maximum-average-subarray-i/

// Author - Vishal Vishwanathan

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {

            double first_k = 0;
            for(int i=0;i<k;i++){
                first_k += nums[i];
            }
            double cur_sum = first_k;
            for(int i=k;i<nums.size();i++){

                cur_sum += nums[i] - nums[i-k];
                first_k = max(cur_sum,first_k);

            }
            return first_k/k;
        }
};


int main() {

    vector<int> v = {1,12,-5,-6,50,3};
    Solution s;
    cout<<s.findMaxAverage(v,4)<<endl;
    return 0;
}
