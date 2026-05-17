class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> words_mp;

        for(int i = 0; i < strs.size(); i++){
            vector<int> hist(26,0);
            for(char c:strs[i]){
                hist[c-'a']++;
            }
            words_mp[hist].push_back(strs[i]);
        }

        vector<vector<string>> ret;
        for(auto [key, anagrams]:words_mp){
            ret.push_back(anagrams);
        }
        return ret;
    }
};
