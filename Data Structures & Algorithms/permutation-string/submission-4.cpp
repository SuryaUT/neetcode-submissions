class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }

        vector<int> s1Count(26,0);
        for(char c:s1){
            s1Count[c -'a']++;
        }

        vector<int> seen(26,0);
        int l = 0;
        for(int r = 0; r < s2.length(); r++){
            int index = s2[r] - 'a';
            seen[index]++;
            while(seen[index] > s1Count[index]){
                seen[s2[l]-'a']--;
                l++;
            }
            if(r-l+1 == s1.length()){
                return true;
            }
        }

        return false;
    }
};
