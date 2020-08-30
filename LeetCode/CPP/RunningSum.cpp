// https://leetcode.com/problems/running-sum-of-1d-array/

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        std::vector<int> runningSumVector;
        runningSumVector.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            runningSumVector.push_back(nums[i] + runningSumVector[i-1]);
        }
        return runningSumVector;
    }
};

int main() {
	Solution S;
	std::vector<int> nums = {1,2,3,4,5,6};
	auto result = S.runningSum(nums);
	for(const auto& x : result) {
		std :: cout << x << " ";
	}
}