// LeetCode Problem : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

// Author : Vishal Vishwanathan

#include <iostream>
#include <cmath>

class Solution {
    int countSetBits(int n){
        int setBitCount = 0;
        while(n>0){
            int mod = n%2;
            setBitCount = mod==1? setBitCount+1: setBitCount;
            n/=2;
        }
        return setBitCount;
    }
    bool isPrime(int n){
        if(n==1) return false;
        for(int i=2;i<sqrt(n);i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
public:
    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for(int i=L;i<=R;i++){
           ans = isPrime(countSetBits(i))?ans+1:ans;
        }
        return ans;
    }
};

int main() {
    Solution s;
    std::cout<<s.countPrimeSetBits(8,10)<<std::endl;
    return 0;
}
