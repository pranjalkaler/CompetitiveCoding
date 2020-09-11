// LeetCode : https://leetcode.com/problems/jewels-and-stones/

// Author : Vishal Vishwanathan

#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        
        for(char c: S){
            if(J.find_first_of(c)!=string::npos)
                count++;
        }
        return count;
    }
};

int main() {
    Solution s;
    cout<<s.numJewelsInStones("aA","aAAbbbb")<<endl;
    return 0;
}
