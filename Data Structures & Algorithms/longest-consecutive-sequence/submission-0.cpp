class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;
        for(int num : st) {
            int streak = 0, curr = num;
            if(st.find(curr - 1) == st.end()) {
                while(st.find(curr) != st.end()) {
                    streak++;
                    curr++;
                }
            }
            res = max(res, streak);
        }
        return res;
    }
};
