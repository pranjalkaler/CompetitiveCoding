// Leetcode : https://leetcode.com/problems/count-primes/

// Author : Vishal Vishwanthan

#include <iostream>
#include <vector>

class Solution {
public:
int countPrimes(int n) {

        if(n==1 || n==0 || n==2) return 0;
        std::vector<bool> v(n,true);
        for(int i=2;i*i<n;i++){
            if(v.at(i-1)==true){
                for(int j = i*i; j<n;j+=i){
                    v.at(j-1)=false;
                }
            }
        }
        int count = 0;
        for(int i=2;i<v.size();i++){
            if(v[i]) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    std::cout<<s.countPrimes(10)<<std::endl;
    return 0;
}
