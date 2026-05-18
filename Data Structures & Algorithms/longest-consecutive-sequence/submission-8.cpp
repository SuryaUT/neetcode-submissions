class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;

        for(int num:nums){
            seen.insert(num);
        }

        vector<int> starts;

        for(int num:nums){
            if(!seen.contains(num - 1)){
                starts.push_back(num);
            }
        }

        int maxS = 0;
        int curMax = 1;
        for(int s:starts){
            while(seen.contains(s+curMax)){
                curMax++;
            }
            maxS = max(curMax,maxS);
            curMax = 1;
        }

        return maxS;
    }
};
