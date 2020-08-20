// LeetCode Question: https://leetcode.com/problems/sum-of-left-leaves/

// Author: Vishal Vishwanathan


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int sum = 0;
    void util(TreeNode* root) {
        if(root==NULL)
            return;
        if(root->left) {
            if(root->left->left == NULL &&
                    root->left->right==NULL)
                sum+= root->left->val;
            util(root->left);
        }
        if(root->right){
            util(root->right);
        }
    }
    public:
    int sumOfLeftLeaves(TreeNode* root) {
        util(root);
        return sum;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout<<s.sumOfLeftLeaves(root)<<endl;
    return 0;
}
