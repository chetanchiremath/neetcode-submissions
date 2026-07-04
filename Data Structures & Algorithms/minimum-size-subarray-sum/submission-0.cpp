class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0, minLen = INT_MAX;
        while(r < n) {
            sum += nums[r];

            while(sum >= target) {
                minLen = min(minLen, r-l+1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return (minLen != INT_MAX) ? minLen : 0;
    }
};