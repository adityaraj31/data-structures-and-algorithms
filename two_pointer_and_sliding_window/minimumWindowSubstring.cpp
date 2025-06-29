class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        vector<int> map(128, 0);
        int m = t.length();
        int l = 0, r = 0, minLen = INT_MAX, startIndex = -1;
        for (char c : t) {
            map[c]++;
        }
        int count = 0;
        while (r < s.length()) {
            if (map[s[r]] > 0) {
                count++;
            }
            map[s[r]]--;
            while (count == m) {
                if (r - l +1< minLen) {
                    startIndex = l;
                    minLen = r - l + 1;
                }
                map[s[l]]++;
                if (map[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};