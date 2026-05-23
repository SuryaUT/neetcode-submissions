class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }

        unordered_map<char,int> s1Chars;
        for(char c:s1){
            s1Chars[c]++;
        }

        unordered_map<char,int> seen;
        int l = 0;
        for(int r = 0; r < s2.length(); r++){
            if(s1Chars[s2[r]]){
                seen[s2[r]]++;
                while(seen[s2[r]] > s1Chars[s2[r]]){
                    seen[s2[l]]--;
                    l++;
                }
                if(r-l+1 == s1.length()){
                    return true;
                }
            } else {
                seen.clear();
                l = r+1;
            }
        }

        return false;
    }
};
