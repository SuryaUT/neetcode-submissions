class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;
        priority_queue<pair<int,int>> maxHeap;

        for(int r = 0; r < nums.size(); r++){
            maxHeap.push({nums[r],r});

            if(r > k - 2){
                while(maxHeap.top().second < r-k+1){
                    maxHeap.pop();
                }
                res.push_back(maxHeap.top().first);
            }
        }

        return res;
    }
};
