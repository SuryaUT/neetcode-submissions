class Solution {
public:
    int characterReplacement(string s, int k) {
        int l= 0;
        int maxLen = 0;
        unordered_map<char,int> charCounts;
        unordered_map<int,int> countCounts;
        //abbcc k=2
        //rule: window is valid if at least one char in that window
        //has at least (window len - k) instances
        //go through array with r pointer
        //charCounts[s[r]]++;
        //countCounts[charCounts[s[r]]]++;
        //is countCounts[l-r+1-k] > 0
        //if yes valid and max len = max(l-r+1,maxLen)
        //else countCounts[charCounts[s[l]]]--; and charCounts[s[l]]--; and l++;
        for(int r = 0; r < s.length(); r++){
            charCounts[s[r]]++;
            countCounts[charCounts[s[r]]]++;
            
            if((r-l-k+1) < 1 || countCounts[r-l-k+1]){
                maxLen = max(r-l+1,maxLen);
            } else {
                countCounts[charCounts[s[l]]]--;
                charCounts[s[l]]--;
                l++;
            }
        }

        return maxLen;
    }
};

//max = 1

/*
    x:1
    y:1
*/

/*
    1:2
    
*/
