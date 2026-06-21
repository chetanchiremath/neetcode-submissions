class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int minLen = INT_MAX, sInd = -1;
        for(int i=0;i<n;i++) {
            vector<int> hash(256, 0);
            for(auto ch : t) hash[ch]++;
            int count = 0;

            for(int j=i;j<n;j++) {
                if(hash[s[j]] > 0) count++;
                hash[s[j]]--;
                if(count == m) {
                    if(j-i+1 < minLen) {
                        minLen = j-i+1;
                        sInd = i;
                    }
                    break;
                }
            }
        }
        return (sInd == -1) ? "" : s.substr(sInd, minLen);
    }
};
