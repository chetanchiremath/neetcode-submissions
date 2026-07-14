class Solution {
public:
    bool canShip(vector<int>& weights, int days, int cap) {
        int n = weights.size();
        int currLoad = 0, totDays = 1;
        for(int i=0;i<n;i++) {
            if(currLoad + weights[i] > cap) {
                currLoad = weights[i];
                totDays++;
            }
            else currLoad += weights[i];
        }
        return totDays <= days;
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