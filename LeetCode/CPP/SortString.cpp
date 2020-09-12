// https://leetcode.com/problems/sort-characters-by-frequency/submissions/
// Author: Pranjal Kaler

#include <bits/stdc++.h>

template<class T>
bool comparePairs(const T& iLhs, const T& iRhs )
{
	if (iLhs.second > iRhs.second) return true;
	return false;
}

class Solution {
public:
	std :: string frequencySort(std :: string s) {

		std :: vector<std :: pair<std :: string, int>> chars;

		for(auto c : s) {
			std :: string singleString(1, c);
			bool flag = true;
			for(auto& x : chars) {
				if(x.first == singleString) {
					x.second++;
					flag = false;
				}
			}
			if(flag) {
				std :: pair<std :: string, int> P(singleString,1);
				chars.push_back(P);
			}
		}

		std :: sort(chars.begin(), chars.end(), comparePairs<std :: pair<std :: string, int>>);
		std :: string result = "";
		for(auto p : chars) {
			while(p.second) {
				result += p.first;
				p.second--;
			}
		}
		return result;
	}
};

int main() {
	std :: string str("abcaba");
	Solution S;
	std :: cout << S.frequencySort(str) << std :: endl;
	return 0;
}