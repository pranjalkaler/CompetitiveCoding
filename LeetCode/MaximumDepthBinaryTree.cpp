//Problem : https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Difficulty : Easy

// Author : Vishal Vishwanathan

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(root)
                return (1 + max(maxDepth(root->left), maxDepth(root->right)));
            else
                return 0;
        }
};

int main() {

    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout<<s.maxDepth(root)<<endl;
    return 0;


}

