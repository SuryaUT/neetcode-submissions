#include <string>

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()){
            return "";
        }

        unordered_map<char,int> tCount, winCount;
        int unique = 0, l = 0, matches = 0;
        pair<int,int> res = {-1,-1};

        for(char c:t){
            if(!tCount[c]){
                unique++;
            }
            tCount[c]++;
        }

        while(!tCount[s[l]] && l <= s.length()){
            l++;
        }

        if(l == s.length()){
            return "";
        }

        for(int r = l; r < s.length(); r++){
            winCount[s[r]]++;

            if(tCount[s[r]] && winCount[s[r]] == tCount[s[r]]){
                matches++;
            }

            while(matches == unique){
                if(r-l+1 < (res.second - res.first + 1) || res.first == -1){
                    res = {l,r};
                }
                if(tCount[s[l]] && winCount[s[l]] == tCount[s[l]]){
                    matches--;
                }
                winCount[s[l]]--;
                l++;
            }
        }

        return res.first == -1 ? "":s.substr(res.first, res.second-res.first + 1);
    }
};
