class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxi = *max_element(weights.begin(), weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);

        for(int cap = maxi; cap <= sum; cap++) {
            int currLoad = 0, totDays = 1;
            for(int i=0;i<n;i++) {
                if(currLoad + weights[i] > cap) {
                    currLoad = weights[i];
                    totDays++;
                }
                else currLoad += weights[i];
            }
            if(totDays <= days) return cap;
        }
        return -1;
    }
};