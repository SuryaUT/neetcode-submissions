class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = nums.size();
        int res = 0;
        
        for(int i = 0; i < 32; i++){
            int mask = 1 << i;
            int x = 0;
            int y = 0;

            for(auto& num:nums){
                x += (num&mask)>>i;
            }

            for(int n = 1; n < l; n++){
                y += (n&mask)>>i;
            }

            if(x > y){
                res |= mask;
            }
        }

        return res;
    }
};
