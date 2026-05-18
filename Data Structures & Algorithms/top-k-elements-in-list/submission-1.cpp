class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //hash map the numbers and their frequencies
        //reverse the hash map to a sorted map frequency:vector of 
        //nums with that frequency
        //go through and append the k most frequent numbers into return vector

        unordered_map<int,int> hash;
        for(int num:nums){
            hash[num]++;
        }
        
        map<int,vector<int>,greater<int>> freq_map;
        for(auto [num,freq]:hash){
            freq_map[freq].push_back(num);
        }

        vector <int> ret;
        for(auto [freq,nums]:freq_map){
            if(nums.size() <= k){
                for(int num:nums){
                    ret.push_back(num);
                }
                k -= nums.size();
            } else {
                for(int i = 0; i < k; i++){
                    ret.push_back(nums[i]);
                }
                return ret;
            }
        }
        return ret;
    }
};
