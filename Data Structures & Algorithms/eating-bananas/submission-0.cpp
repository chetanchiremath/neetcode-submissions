class Solution {
public:
    long long calculateTotalHours(vector<int>& nums, int k) {
        long long totHours = 0;
        for(int i=0;i<nums.size();i++) {
            totHours += ceil((double)nums[i] / (double)k);
        }
        return totHours;
    }

    int minEatingSpeed(vector<int>& nums, int h) {
        int maxi = *max_element(nums.begin(), nums.end());
        int low = 1, high = maxi;
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            long long totHours = calculateTotalHours(nums, mid);

            if(totHours <= h) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};