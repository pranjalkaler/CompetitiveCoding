//LeetCode : https://leetcode.com/problems/linked-list-cycle-ii

// Author: Vishal Vishwanathan


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        set<ListNode*> s; 
        while(head) {
            if(s.count(head))
                break;
            s.insert(head);
            head = head->next;
        }
        return head;
    }
};

int main() {
    
    ListNode* head = new ListNode(3);
    ListNode* pos1 = new ListNode(2);
    head->next = pos1;
    ListNode* pos2 = new ListNode(0);
    pos1->next = pos2;
    ListNode* pos3 = new ListNode(-4);
    pos2->next = pos3;
    pos3->next = pos1;
    
    Solution s;
    cout<<s.detectCycle(head)->val<<endl;
    return 0;
}
