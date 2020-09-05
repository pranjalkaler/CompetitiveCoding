// Leetcode: https://leetcode.com/problems/serialize-and-deserialize-bst/


// Author: Vishal Vishwanathan


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


class Codec{

    void helper(TreeNode* root, std::string& s) {
        if(!root)
            return;
        s += std::to_string(root->val)+" ";
        helper(root->left, s);
        helper(root->right, s);
    }

    TreeNode* vecToTreeNode(std::vector<int> v, int start, int end) {
        if(start>=end)
            return nullptr;

        TreeNode* ret = new TreeNode(v[start]);
        int index = start;
        while(index<end && v[start]>=v[index])
            index++;
        ret->left = vecToTreeNode(v, start+1, index);
        ret->right = vecToTreeNode(v,index,end);
        return ret;

    }
public:
    std::string serialize(TreeNode* root) {
        std::string s="";
        helper(root,s);
        return s;
    }
    TreeNode* deserialize(std::string data) {
        if(data == " ")
            return nullptr;
        std::vector<int> v;
        std::string s;
        std::stringstream sStream(data);

        //Read every element from the data , until a space
        while(getline(sStream,s,' ')) {
            v.push_back(stoi(s));
        }
        return vecToTreeNode(v,0,v.size());

    }
};

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(22);
    
    Codec c;
    std::cout<<c.serialize(root)<<std::endl;
    TreeNode* dRoot = c.deserialize(c.serialize(root));
    return 0;
}
