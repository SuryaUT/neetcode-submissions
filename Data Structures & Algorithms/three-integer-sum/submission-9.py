class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        res = []

        s = nums.sort()
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            target = -nums[i]
            l = i + 1
            r = len(nums) - 1 
            while l < r:
                s = nums[l] + nums[r]
                if s == target:
                    res.append([nums[i], nums[l], nums[r]])
                    l += 1
                    r -= 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
                elif s < target:
                    l += 1
                else:
                    r -= 1

        return res