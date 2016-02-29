class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0, left = 0;
        int sz = s.length();
        int prev[500];
        memset(prev, -1, sizeof(prev));
        
        for(int i = 0; i < sz; i++){
            if(prev[s[i]] >= left){
                left = prev[s[i]] + 1;
            }
            prev[s[i]] = i;
            maxlen = max(maxlen, i - left + 1);
        }
        return maxlen;
    }
};