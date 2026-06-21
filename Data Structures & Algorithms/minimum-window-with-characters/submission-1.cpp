class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int minLen = INT_MAX, sInd = -1;
        vector<int> hash(256, 0);
        for(auto ch : t) hash[ch]++;
        int count = 0;

        int l = 0, r = 0;
        while(r < n) {
            if(hash[s[r]] > 0) count++;
            hash[s[r]]--;

            while(count == m) {
                if(r-l+1 < minLen) {
                    minLen = r-l+1;
                    sInd = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) count--;
                l++;
            }
            r++;
        }
        return (sInd == -1) ? "" : s.substr(sInd, minLen);
    }
};
