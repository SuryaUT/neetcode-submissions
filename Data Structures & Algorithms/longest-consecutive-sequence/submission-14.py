class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        seen = set(nums)

        res = 0

        starts = []
        for num in nums:
            if num - 1 not in seen:
                starts.append(num)

        for s in starts:
            cur = s
            while cur + 1 in seen:
                cur += 1
            res = max(cur-s+1,res)

        return res