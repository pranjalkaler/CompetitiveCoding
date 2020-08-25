//Leetcode : https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

//Author: Vishal Vishwanathan

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;
        
        for(int i=1;i<=n/2;i++){
            v.push_back(i);
            v.push_back(i*(-1));
        }
        if(n%2!=0)
            v.push_back(0);
        
        return v;
        
    }
};

int main() {
    Solution s;
    for(auto x: s.sumZero(5)){
        cout<<x<<endl;
    }
}
