// LeetCode : https://leetcode.com/problems/guess-number-higher-or-lower

// Author: Vishal Vishwanathan

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

#include <iostream>

int theNumber = 6;
int guess(int num){
    if(num==theNumber)
        return 0;
    else if(num>theNumber)
        return 1;
    else
        return -1;
}
class Solution {
public:
    int guessNumber(int n) {
           
        long long int beg=1, end=n;
        long long int mid = (beg+end)/2;
        while(1){
            
            if(!guess(mid))
                return mid;
            else if(guess(mid)==1) {
                end = mid-1;
                mid=(beg+end)/2;
            }
            else if(guess(mid)==-1){
                beg=mid+1;
                mid = (beg+end)/2;
            }
        }
        return n;
    }
};

int main() {
    Solution s;
    std::cout<<s.guessNumber(11)<<std::endl;
    return 0;
}
