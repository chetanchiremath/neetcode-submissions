class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256, 0);
        for(auto &ch : t) freq[ch]++;

        int n = s.size(), m = t.size();
        int count = 0, start = -1, minLen = INT_MAX;
        int l = 0, r = 0;
        while(r < n) {
            if(freq[s[r]] > 0) count++;
            freq[s[r]]--;

            while(count == m) {
                if(r-l+1 < minLen) {
                    minLen = r-l+1;
                    start = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) count--;
                l++;
            }
            r++;
        }
        return (start == -1) ? "" : s.substr(start, minLen);
    }
};
