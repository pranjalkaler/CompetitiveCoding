// LeetCode: https://leetcode.com/problems/excel-sheet-column-number/

// Author: Vishal Vishwanathan


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int titleNumber(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++) {
            sum = (sum*26) + ((int) (s[i]-'A') +1);
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout<<s.titleNumber("BC")<<endl;
}
