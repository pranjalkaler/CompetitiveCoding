#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
	int n;
	cin>>n;
	int x[n],y[n];
	for(int i=0;i<n;i++){
		cin>>y[i]>>x[i];
	}

	set<int> s;
	for(int i=0;i<n;i++){
		switch(y[i]){
			case 1: 
				s.insert(x[i]);
				break;
			case 2: 
				{
					set<int>::iterator itr1 = s.find(x[i]);
					if(itr1 != s.end())
						s.erase(x[i]);
				}
				break;
			case 3:
				{
					set<int>::iterator itr2 = s.find(x[i]);                    
					if(itr2 != s.end())
						cout<<"Yes"<<endl;
					else
						cout<<"No"<<endl;
				}
				break;
		}
	}
	return 0;
}




