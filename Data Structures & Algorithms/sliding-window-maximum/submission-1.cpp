class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;
        priority_queue<pair<int,int>> maxHeap;

        for(int i = 0; i < k; i++){
            maxHeap.push({nums[i],i});
        }

        res.push_back(maxHeap.top().first);

        for(int r = k; r < nums.size(); r++){
            int l = r-k+1;
            maxHeap.push({nums[r],r});

            while(maxHeap.top().second < l){
                maxHeap.pop();
            }

            res.push_back(maxHeap.top().first);
        }

        return res;
    }
};
