// LeetCode Problem: https://leetcode.com/problems/sort-characters-by-frequency

// Author: Vishal Vishwanathan
#include <iostream>
#include <bits/stdc++.h>

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for(char c: s){
            m[c]++;
        }
        
        vector<pair<char,int>> v(m.begin(), m.end());
        
        sort(v.begin(), v.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });
        
        
        stringstream ss;
        int i = 0;
        for(auto x : v) {
            while(x.second){
                ss<<x.first;
                x.second--;
            }
        }        
        return ss.str();
    }
};

int main() {
    Solution s;
    std::cout<<s.frequencySort("tree")<<endl;
}
