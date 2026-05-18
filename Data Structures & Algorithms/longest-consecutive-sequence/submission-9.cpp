class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;

        for(int num:nums){
            seen.insert(num);
        }



        int maxS = 0;
        
        for(int num:nums){
            if(!seen.contains(num - 1)){
                int curMax = 1;
                while(seen.contains(num+curMax)){
                    curMax++;
                }
                maxS = max(curMax,maxS);
            }
        }

        return maxS;
    }
};
