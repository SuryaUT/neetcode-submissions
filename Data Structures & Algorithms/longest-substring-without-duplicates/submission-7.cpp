class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() < 2){
            return s.length();
        }
        int maxLen = 0;
        int l=0, r=0;
        unordered_set<char> seen;

        while(r < s.length()){
            if(seen.contains(s[r])){
                maxLen = max(maxLen, r-l);
                while(s[l] != s[r]){
                    seen.erase(s[l]);
                    l++;
                }
                l++;
            } else {
                seen.insert(s[r]);
            }
            r++;
        }

        maxLen = max(maxLen, r-l);
        return maxLen;
    }
};
