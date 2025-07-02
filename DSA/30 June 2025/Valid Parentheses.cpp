// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0){
            return false;
        }

        stack<char> st;
        for (auto x: s){
            if ((x == '(') || (x == '[') || (x == '{')){
                st.push(x);
            } else if (st.empty() || ( x==')' && st.top()!='(') || (x=='}' && st.top()!='{') || (x==']' && st.top()!='[')){
                return false;
            } else {
                st.pop();
            }
        }
        if (st.empty()){
            return true;
        }
        return false;
    }
};