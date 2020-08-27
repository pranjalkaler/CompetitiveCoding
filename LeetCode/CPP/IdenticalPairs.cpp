// Leetcode : https://leetcode.com/problems/number-of-good-pairs/

// Author : Vishal Vishwanathan

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
    public:
        int numIdenticalPairs(vector<int>& nums) {
            int count = 0;
            unordered_map<int,int> m;
            for(int i=0;i<nums.size();i++){
                if(m.find(nums[i])!=m.end()) {
                    count += m[nums[i]];
                }
                m[nums[i]]++;
            }
            return count;
        }
};

int main() {
    Solution s;
    vector<int> v = {1,1,1,1};
    cout<<s.numIdenticalPairs(v)<<endl;
}
