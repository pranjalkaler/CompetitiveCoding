// LeetCode question - https://leetcode.com/problems/search-insert-position/

// author: Vishal Vishwanathan

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int beg = 0; 
    int end = nums.size()-1;
    
    if(nums.at(beg)>target) return 0;
    
    if(nums.at(end)<target) return nums.size();
    
    while(beg<=end){
        if(target==nums.at(beg))
            return beg;
        else if(target == nums.at(end))
            return end;
        else {
            if (nums.at(beg)<target)
                beg++;
            if (nums.at(end)>target)
                end--;
        }
    }
    return beg;
}

int main() {

    std::vector<int> nums = {1, 3, 5, 6};
    cout<<searchInsert(nums, 2)<<endl;
    return 0;

}
