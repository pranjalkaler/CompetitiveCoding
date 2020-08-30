//LeetCode: https://leetcode.com/problems/keyboard-row/

// Author: Vishal Vishwanathan

#include <iostream>
#include <bits/stdc++.h>

class Solution {
    public:
        std::vector<std::string> findWords(std::vector<std::string>& words) {
            std::set<char>row1={'Q','W','E','R','T','Y','U','I','O','P','q','w','e','r','t','y','u','i','o','p'};
            std::set<char>row2={'A','S','D','F','G','H','J','K','L','a','s','d','f','g','h','j','k','l'};
            std::set<char>row3={'Z','X','C','V','B','N','M','z','x','c','v','b','n','m'};
            std::vector<std::string>res;

            for(int i=0;i<words.size();i++){
                int r1=0,r2=0,r3=0;
                for(char c: words[i]){
                    if(row1.find(c)!=row1.end()){
                        r1++;
                    }
                    else if(row2.find(c)!=row2.end()){
                        r2++;
                    }
                    else{
                        r3++;
                    }
                }

                if(r1==words[i].size() || r2==words[i].size() || r3==words[i].size())
                    res.push_back(words[i]);
            }
            return res;
        }
};


int main() {
    Solution s;

    std::vector<std::string> v = {"Hello","Alaska","Dad","Peace"};
    for(auto x: s.findWords(v)){
        std::cout<<x<<std::endl;
    }
}
