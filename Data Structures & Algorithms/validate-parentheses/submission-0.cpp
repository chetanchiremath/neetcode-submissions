class Solution {
public:
    bool isValid(string str) {
        int n = str.size();
        stack<char> st;
        for(char& ch : str) {
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else if(!st.empty()) {
                cout << st.top() << endl;
                if (ch == ')' && st.top() == '(') st.pop(); 
                else if (ch == '}' && st.top() == '{') st.pop(); 
                else if (ch == ']' && st.top() == '[') st.pop();
                else return false;
            }
            else return false;
        }
        return st.empty() ? true : false;
    }
};