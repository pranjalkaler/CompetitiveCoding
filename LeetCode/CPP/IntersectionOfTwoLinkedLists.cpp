// LeetCode: https://leetcode.com/problems/intersection-of-two-linked-lists/
// Authod: Pranjal Kaler

#include <bits/stdc++.h>

struct ListNode {

    int val;
    std :: shared_ptr<ListNode> next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:

    void addToList(std :: shared_ptr<ListNode>& head, std :: shared_ptr<ListNode> val) {
        if(head == nullptr) {
            head = val;
            return;
        }
        auto temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = val;
    }

    std :: shared_ptr<ListNode> getIntersectionNode(std :: shared_ptr<ListNode> headA, std :: shared_ptr<ListNode> headB) {
        if(headA == nullptr || headB == nullptr) {
            std :: cout << "Empty lists" << std :: endl;
            return nullptr;
        }
        
        int lengthA = 0;
        auto tempA = headA;
        while(tempA != nullptr) {
            ++lengthA;
            tempA = tempA->next;
        }
        
        int lengthB = 0;
        auto tempB = headB;
        while(tempB != nullptr) {
            ++lengthB;
            tempB = tempB->next;
        }
        
        
        tempA = headA;
        tempB = headB;
        
        auto diff = std :: abs(lengthA - lengthB);
        
        while(diff) {
            if(lengthA > lengthB) {
                tempA = tempA->next;
            }
            else {
                tempB = tempB->next;
            }
            diff--;
        }
        
        while(tempA && tempB) {
            if(tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return nullptr;   
    }
};




int main() {
    Solution S;
    std :: shared_ptr<ListNode> A = std :: make_shared<ListNode>(1);
    std :: shared_ptr<ListNode> B = std :: make_shared<ListNode>(2);
    std :: shared_ptr<ListNode> C = std :: make_shared<ListNode>(3);
    std :: shared_ptr<ListNode> D = std :: make_shared<ListNode>(4);
    std :: shared_ptr<ListNode> E = std :: make_shared<ListNode>(5);
    std :: shared_ptr<ListNode> F = std :: make_shared<ListNode>(6);
    std :: shared_ptr<ListNode> G = std :: make_shared<ListNode>(7);
    std :: shared_ptr<ListNode> H = std :: make_shared<ListNode>(8);
    std :: shared_ptr<ListNode> I = std :: make_shared<ListNode>(9);
    std :: shared_ptr<ListNode> J = std :: make_shared<ListNode>(10);

    std :: shared_ptr<ListNode> headA;
    std :: shared_ptr<ListNode> headB;
    S.addToList(headA, A);
    S.addToList(headA, B);
    S.addToList(headA, C);
    S.addToList(headA, D);
    S.addToList(headA, E);
    S.addToList(headA, F);
    S.addToList(headA, G);

    S.addToList(headB, J);
    S.addToList(headB, I);
    S.addToList(headB, H);
    S.addToList(headB, D);

    auto commonNode = S.getIntersectionNode(headA, headB);
    std :: cout << "InterSection at: " << commonNode->val << std :: endl;
    return 0;
}