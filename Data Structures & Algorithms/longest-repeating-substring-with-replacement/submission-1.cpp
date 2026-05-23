class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxLen = 0;
        int maxFreq = 0;
        unordered_map<char,int> counts;

        for(int r = 0; r < k; r++){
            counts[s[r]]++;
            maxFreq = max(counts[s[r]], maxFreq);
        }

        for(int r = k; r < s.length(); r++){
            counts[s[r]]++;
            maxFreq = max(counts[s[r]], maxFreq);
            
            while(r-l-k+1 > maxFreq){
                counts[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};