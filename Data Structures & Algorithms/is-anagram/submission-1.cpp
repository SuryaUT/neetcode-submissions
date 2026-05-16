class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char,int> letters_s;
        unordered_map<char,int> letters_t;
        for(int i = 0; i < s.length(); i++){
            letters_s[s[i]]++;
            letters_t[t[i]]++;
        }
        if(letters_s == letters_t){
            return true;
        }
        return false;
    }
};
