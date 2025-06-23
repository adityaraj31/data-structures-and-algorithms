// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        int maxlen = 0, l=0, r=0;
        unordered_map<char, int> map;
        
        while(r < s.length()) {
            
            map[s[r]]++;
            
            if(map.size() > k) {
                map[s[l]]--;
                if(map[s[l]] == 0)
                    map.erase(s[l]);
                l++;
            }
            
            if(map.size() <= k) 
                maxlen = max(maxlen, r - l + 1);
            
            r++;            
        }
        return maxlen;
    }
};