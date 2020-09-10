// LeetCode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock

// Author: Vishal Vishwanathan

#include <iostream>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        
        if(prices.size()<=1) return 0;
        
        int buy = prices[0];
        int ans = 0;
        for(int i=0;i<prices.size();i++){
            // check if the current buying price less than previous price
            if(prices[i]<buy)
                buy = prices[i];
            // if not, that means we can sell to see profit 
            else
                ans = std::max(prices[i]-buy, ans); // check for max profit
        }
        return ans;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {7,1,5,3,6,4};
    std::cout<<s.maxProfit(v)<<std::endl;
}
