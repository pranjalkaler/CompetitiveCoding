// Problem : https://leetcode.com/problems/first-unique-character-in-a-string

// Author : Vishal Vishwanathan

#include <iostream>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        
        int count[26] = { 0 }; 
        for( char c: s){
            count[c-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(count[s[i]-'a']==1)
                return i;
        }
        return -1;   
    }
};


int main()
{
    Solution s;
    cout<<s.firstUniqChar("leetcode")<<endl;
    return 0;
}
