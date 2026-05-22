class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int maxLen = 0;
        int l=0, r=0;
        unordered_set<char> seen;

        for(int r = 0; r < s.length(); r++){
            while(seen.contains(s[r])){
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};
