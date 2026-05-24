#include <string>

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tCount;
        unordered_map<char,int> winCount;
        for(char c:t){
            tCount[c]++;
        }

        //window is valid if it doesnt satisfy solution yet
        int l = 0;
        bool valid;
        while(!tCount[s[l]] && l <= s.length()){
            l++;
        }

        if(l == s.length()){
            return "";
        }

        string res = "";
        string cur = "";

        for(int r = l; r < s.length(); r++){
            cur += s[r];
            winCount[s[r]]++;

            valid = true;
            for(auto [c,count]:tCount){
                if(winCount[c] < count){
                    valid = false;
                }
            }

            while(valid){
                if(r-l+1 < res.length() || res.length() == 0){
                    res = "";
                    for(int i = l; i <= r; i++){
                        res += s[i];
                    }
                }
                winCount[s[l]]--;
                l++;

                valid = true;
                for(auto [c,count]:tCount){
                    if(winCount[c] < count){
                        valid = false;
                    }
                }
            }
        }

        return res;
    }
};
