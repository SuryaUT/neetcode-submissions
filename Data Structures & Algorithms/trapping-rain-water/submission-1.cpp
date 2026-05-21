class Solution {
public:
    int trap(vector<int>& height) {
        //start at both sides of the array
        //create a left max array and right max array
        //for each point compute the max value to the left and right
        //go through and calculate area at each point using the formula
        //area[i] = min(leftMax[i],rightMax[i])-height[i] and add it to
        //total area if non negative

        vector<int> leftMax(height.size(),0);
        vector<int> rightMax(height.size(),0);
        for(int i = 1; i < height.size() - 1; i++){
            leftMax[i] = max(leftMax[i-1],height[i-1]);
            rightMax[height.size()-i-1] = max(rightMax[height.size()-i],height[height.size()-i]);
        }

        int area = 0;
        for(int i = 0; i < height.size(); i++){
            area += max(0, min(leftMax[i],rightMax[i])-height[i]);
        }

        return area;
    }
};
