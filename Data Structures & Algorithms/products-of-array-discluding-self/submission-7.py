class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        zero_count = 0
        for num in nums:
            if num == 0:
                zero_count += 1
        
        if zero_count > 1:
            return [0]*len(nums)

        l = len(nums)
        pre = [1]*l
        post = [1]*l

        for i in range(1, l):
            pre[i] = pre[i-1]*nums[i-1]
            post[l - i - 1] = post[l-i]*nums[l-i]

        res = []

        for i in range(l):
            res.append(pre[i]*post[i])

        return res