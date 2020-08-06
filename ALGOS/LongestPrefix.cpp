#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void longestPrefix(std::vector<std::string> a){

	std::vector<char> ans;
	std::sort(a.begin(), a.end());
    std::string first = a.at(0);
	std::string second = a.at(a.size()-1);

	for(int i=0, j=0; i!=first.length() && j!=second.length(); i++, j++){
		if (first[i] == second[j])
			ans.push_back(first[i]);
		else
			break;
	}	

	cout<<std::string(ans.begin(),ans.end())<<endl;	

}

int main() {
	std::vector<std::string> a;
	a.push_back("dog");
	a.push_back("racecar");
	a.push_back("car");
	
	longestPrefix(a);

}
