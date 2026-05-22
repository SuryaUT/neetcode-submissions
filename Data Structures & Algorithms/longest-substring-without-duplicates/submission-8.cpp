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
            while(seen.contains(s[r])){
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};
