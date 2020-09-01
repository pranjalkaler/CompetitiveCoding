// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/submissions/

#include <bits/stdc++.h>

class Node {
    int val;
    std :: vector<Node*> children;
public:
    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std :: vector<Node*> _children) {
        val = _val;
        children = _children;
    }
    
    std :: vector<Node*> getChildren() {
        return children;
    }
    
    void setChildren(std :: vector<Node*>& vc) {
        this->children = vc;
    }
};

class Solution {
public:
    int maxDepth(Node* root);
};

int Solution :: maxDepth(Node* root) {
    if(root == nullptr)
        return 0;
    int md = 1;
    for(auto node : root->getChildren()) {
        int d = maxDepth(node) + 1;
        md = (d > md) ? d : md;
    }
    return md;
}

int main() {
    Node* A = new Node(1);
    Node* B = new Node(2);
    Node* C = new Node(3);
    Node* D = new Node(4);
    Node* E = new Node(5);
    Node* F = new Node(6);
    Node* G = new Node(7);
    std :: vector<Node*> row1 = {B, C, G};
    std :: vector<Node*> row2 = {D, E, F};
    A->setChildren(row1);
    B->setChildren(row2);
    
    Solution S;
    std :: cout << "Max Depth: " << S.maxDepth(A) << std :: endl;   
}

