// Problem from codeforces 
// https://codeforces.com/problemset/problem/1367/A

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


std::string ComputeAnswer(std::string x) {
	std::vector<char> out;
	out.push_back(x[0]);
	for(int i=1;i<=x.length()-2;){
		out.push_back(x[i]);
		i+=2;
	}
	out.push_back(x[x.length()-1]);
	return std::string(out.begin(), out.end());
}

int main() {

	int t;
	cin>>t;
	vector<std::string> data;
	for(int i=0;i<t;i++) {
		std::string temp;
		cin>>temp;
		data.push_back(temp);
	}

	for(std::string x : data){
		cout<<ComputeAnswer(x)<<endl;
	}
	return 0;
}
