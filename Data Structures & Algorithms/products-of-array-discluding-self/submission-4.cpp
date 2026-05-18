class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int zeros = 0;

        for (int num:nums){
            if(num != 0){
                prod *= num;
            } else {
                zeros++;
            }
        }

        vector<int> ret;

        if(zeros){
            if(zeros > 1){
                for(int num:nums){
                    ret.push_back(0);
                }
                return ret;
            }
            for(int num:nums){
                if(num != 0){
                    ret.push_back(0);
                } else {
                    ret.push_back(prod);
                }
            }
        } else {
            for(int num:nums){
                ret.push_back(prod/num);
            }
        }
        return ret;
    }
};
