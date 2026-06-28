class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0, j = n-1;
        int res = 0;
        while(i < j) {
            int area = (j - i) * min(heights[i], heights[j]);
            res = max(res, area);
            if(heights[i] <= heights[j]) i++;
            else j--;
        }
        return res;
    }
};
