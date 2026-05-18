class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;

        int maxS = 0;
        for(int num:nums){
            if(!mp[num]){
                int curr = mp[num - 1] + mp[num + 1] + 1;
                mp[num]++;
                mp[num - mp[num - 1]] = curr;
                mp[num + mp[num + 1]] = curr;
                maxS = max(maxS, curr);
            }
        }

        return maxS;
    }
};
