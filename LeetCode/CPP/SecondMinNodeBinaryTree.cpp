// Leetcode :https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

// Author: Vishal Vishwanathan

#include <bits/stdc++.h>
#include <iostream>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
    ~TreeNode() {
        delete this->left;
        delete this->right;
    }
};

class Solution {

    std::set<int> s;

    void util(TreeNode* root){
        if(root){
            util(root->left);
            s.insert(root->val);
            util(root->right);
        }
        return;
    }

    public:
    int findSecondMinimumValue(TreeNode* root) {
        util(root);
        int count = 2;
        for(auto& e:s) {
            if(!--count) {
                return  e;
            }
        }
        return -1;
    }
};

int main() {

    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    Solution s;

    std::cout<<s.findSecondMinimumValue(root)<<std::endl;

    return 0;

}
