// LeetCode: https://leetcode.com/problems/find-the-difference/

// Author: Vishal Vishwanathan

#include <iostream>

class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        int diff = 0;
        for(char c : t){
            diff += c-'a';
        }
        for(char c: s){
            diff -= c -'a';
        }
        return diff+'a';
        
    }
};

int main() {
    Solution s; 
    std::cout<<s.findTheDifference("abcd","abcde")<<std::endl;
}
