// Leetcode : https://leetcode.com/problems/plus-one/

//Author : Vishal Vishwanathan


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {

            if(!digits.size()) return digits;
            bool done = false;
            int pos = digits.size()-1;

            while(!done && pos>=0) {

                if(digits[pos] < 9){
                    digits[pos]
                        =
                        digits[pos]+1;
                    return
                        digits;
                }
                else
                    if(digits[pos]==9){
                        digits[pos]=0;
                        pos--;
                    }
            }
            digits.insert(digits.begin(),1);
            return
                digits;
        }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3};
    s.plusOne(nums);
    
    for( auto x: nums)
        cout<<x<<endl;

    return 0;
}
