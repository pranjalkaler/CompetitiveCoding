#include <bits/stdc++.h>

class Solution {
public:
    bool isValid(std::string s) {
        std :: stack<char> S;
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                S.push(s[i]);
            else if(!S.empty()) {
                if(S.top() == '(' && s[i] == ')')
                    S.pop();
                else if(S.top() == '{' && s[i] == '}')
                    S.pop();
                else if(S.top() == '[' && s[i] == ']')
                    S.pop();
                else 
                    S.push(s[i]);
            }
            else {
                return false;
            }
        }
        if(S.empty())
            return true;
        else 
            return false;
    }
};

int main() {
	Solution S;
	std :: cout << S.isValid("()()()()") << " "
				<< S.isValid("(((((()())") << " "
				<< S.isValid("[{[{]}]}") << " "
				<< S.isValid("{[[{}]]}") << " "
				<< S.isValid("(({{[[]]}}))") << " "
				<< S.isValid("") << " ";
}