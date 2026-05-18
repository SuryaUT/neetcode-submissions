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
        
        priority_queue<pair<int,int>, 
            vector<pair<int,int>>, 
            greater<pair<int,int>>> heap;
        
        for(auto& [num,freq]:hash){
            heap.push({freq,num});
            if(heap.size() > k){
                heap.pop();
            }
        }

        vector<int> ret;
        for(int i = 0; i < k; i++){
            ret.push_back(heap.top().second);
            heap.pop();
        }
        return ret;
    }
};
