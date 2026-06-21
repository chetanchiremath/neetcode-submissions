class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        unordered_map<char, int> mpp1, mpp2;
        for(char c : s1) mpp1[c]++;
        int l = 0, r = 0;
        while(r < s2.size()) {
            mpp2[s2[r]]++;
            r++;
            if(r-l == n) {
                if(mpp1 == mpp2) return true;
                mpp2[s2[l]]--;
                if(mpp2[s2[l]] == 0) mpp2.erase(s2[l]);
                l++;
            }
        }
        return false;
    }
};
