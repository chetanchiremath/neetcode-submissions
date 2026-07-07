class Solution {
public:
    bool canShip(vector<int>& arr, int days, int cap) {
        int n = arr.size();
        int reqDays = 1, currLoad = 0;
        for(int i=0;i<n;i++) {
            if(currLoad + arr[i] > cap) {
                reqDays++;
                currLoad = arr[i];
            }
            else currLoad += arr[i];
        }
        return reqDays <= days;
    }

    int shipWithinDays(vector<int>& arr, int days) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(canShip(arr, days, mid)) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};