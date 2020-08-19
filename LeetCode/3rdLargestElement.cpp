// Leet Code Problem: https://leetcode.com/problems/third-maximum-number/

// Author: Vishal Vishwanathan


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int thirdMax(vector<int>& nums) {

            std::map<int, int> m;
            for(auto x: nums) {
                m[x]++;
            }
            int count = m.size();

            int target = count -3 ;

            map<int,
                int>::iterator it =
                    m.end();

            if(target<0){
                it--;
                return
                    it->first;
            }

            it
                =
                m.begin();
            while(target>=0){
                if(target==0)
                    break;
                else
                    target--;
                it++;
            }
            return
                it->first;

        }
};

int main() {
    std::vector<int> v = {1,2,2,5,3,5};
    Solution s; 
    cout<<s.thirdMax(v)<<endl;
}
