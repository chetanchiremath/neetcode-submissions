class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        
        int res = 0;
        for(int i=0;i<n;i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                int ind = st.top();
                st.pop();

                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                int area = heights[ind] * (nse - pse - 1);
                res = max(res, area);
            }
            st.push(i);
        }

        while(!st.empty()) {
            int ind = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            int area = heights[ind] * (nse - pse - 1);
            res = max(res, area);
        }
        return res;
    }
};
