class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int num:nums){
            mp[num]++;
        }

        vector<int> starts;

        for(int num:nums){
            if(!mp.contains(num - 1)){
                starts.push_back(num);
            }
        }

        int max = 0;
        int curMax = 1;
        for(int s:starts){
            while(mp.contains(s+curMax)){
                curMax++;
            }
            if(curMax > max){
                max = curMax;
            }
            curMax = 1;
        }

        return max;
    }
};
