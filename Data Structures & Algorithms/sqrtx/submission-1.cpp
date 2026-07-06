class Solution {
public:
    int mySqrt(int n) {
        int low = 0, high = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            long long val = (long long)mid * mid;

            if(val <= n) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return high;
    }
};