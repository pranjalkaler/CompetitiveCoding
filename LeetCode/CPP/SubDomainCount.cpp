// LeetCode: https://leetcode.com/problems/subdomain-visit-count/

// Author : Vishal Vishwanathan
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for(string s: cpdomains){
            int d = s.find_first_of(' ');
            int count = stoi(s.substr(0,d));
            string dom = s.substr(d, s.size());
            
            for(int i=0;i!=string::npos;i=dom.find_first_of('.',i)){
                string sub = dom.substr(i++);
                m[sub.substr(1)] += count;
            }   
        }
        vector<string> out;
        for(auto i: m){
            out.emplace_back(to_string(i.second)+" "+i.first);
        }
        return out;
    }
};

int main() {

    Solution s;
    vector<string> v = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    s.subdomainVisits(v);
    return 0;
}
