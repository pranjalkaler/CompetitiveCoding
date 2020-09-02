// Leetcode : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

// Author : Vishal Vishwanathan

#include <iostream>
#include <bits/stdc++.h>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() {
        delete this->left;
        delete this->right;
    }
};


class Solution {
    TreeNode* util(std::vector<int> nums, int start, int end ){
        if(start<=end){
            int mid = start + (end-start)/2;
            TreeNode* x = new TreeNode(nums[mid]);
            x->left = util(nums, start,mid-1);
            x->right = util(nums, mid+1,end);
            return x;
        }
        return nullptr;
    }
    public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return util(nums,0,nums.size()-1);
    }
};


int main() {

    Solution s;
    std::vector<int> v = {10,-3,0,5,9};
    TreeNode* root = s.sortedArrayToBST(v);
    return 0;
}

