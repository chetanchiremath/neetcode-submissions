class Solution {
public:
    bool isMatched(char open, char close) {
        if((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']')) return true;
        return false;
    }

    bool isValid(string str) {
        int n = str.size();
        stack<char> st;
        for(char& ch : str) {
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else {
                if(st.empty()) return false;

                char c = st.top();
                st.pop();
                if(!isMatched(c, ch)) return false;
            }
        }
        return st.empty();
    }
};