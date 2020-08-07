#include <iostream>
#include <stack>

using namespace std;
class Solution {
    public:
        bool isValid(string s) {
            std::stack<char> st;
            for(char c: s){
                switch(c){
                    case '{':
                    case '[':
                        case
                            '(':
                            st.push(c);
                        break;
                        case
                            '}':
                            if
                                (!st.empty()
                                 &&
                                 st.top()=='{')
                                    st.pop();
                            else
                                return
                                    false;
                        break;
                        case
                            ']':
                            if
                                (!st.empty()
                                 &&
                                 st.top()=='[')
                                    st.pop();
                            else
                                return
                                    false;
                        break;
                        case
                            ')':
                            if
                                (!st.empty()
                                 &&
                                 st.top()=='(')
                                    st.pop();
                            else
                                return
                                    false;
                        break;
                    default:
                        return
                            false;
                }
            }
            return
                st.empty();
        }
};


int main() {
    return 0;
}
