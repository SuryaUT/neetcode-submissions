class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;

        int maxS = 0;
        for(int num:nums){
            if(!mp[num]){
                mp[num] = mp[num - 1] + mp[num + 1] + 1;
                mp[num - mp[num - 1]] = mp[num];
                mp[num + mp[num + 1]] = mp[num];
                maxS = max(maxS, mp[num]);
            }
        }

        return maxS;
    }
};
