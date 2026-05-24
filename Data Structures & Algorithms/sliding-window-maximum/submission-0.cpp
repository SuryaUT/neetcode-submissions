class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;
        priority_queue<int> maxHeap;
        unordered_map<int, int> idx;

        for(int i = 0; i < k; i++){
            maxHeap.push(nums[i]);
            idx[nums[i]] = i;
        }

        res.push_back(maxHeap.top());

        for(int r = k; r < nums.size(); r++){
            int l = r-k+1;
            idx[nums[r]] = r;
            maxHeap.push(nums[r]);

            while(idx[maxHeap.top()] < l){
                maxHeap.pop();
            }

            res.push_back(maxHeap.top());
        }

        return res;
    }
};
