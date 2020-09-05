// LeetCode: https://leetcode.com/problems/build-an-array-with-stack-operations/

#include <bits/stdc++.h>

class Solution {
    const std :: string kPUSH = "Push";
    const std :: string kPOP = "Pop";
public:
    std :: vector<std :: string> buildArray(std :: vector<int>& target, int n) {
        int pos = 0;
        std :: vector<std :: string> result;
        for(int i = 1; i<=n; i++) {
            if(pos < target.size() && i <= target[pos]) {
                if(i == target[pos]) {
                    result.push_back(kPUSH);
                    pos++;
                }
                else {
                    result.push_back(kPUSH);
                    result.push_back(kPOP);
                }
            }
        }
        return result;
    }
};




int main() {
    std::vector<int> array = {1, 3};
    Solution S;
    auto result = S.buildArray(array, 3);
    for(auto& x : result) {
        std :: cout << x << " ";
    }
}

