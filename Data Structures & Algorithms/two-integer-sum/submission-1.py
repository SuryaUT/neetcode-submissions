class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = {}
        for i, num in enumerate(nums):
            n[num] = i

        for i, num in enumerate(nums):
            diff = target - num
            if (diff) in n and n[diff] != i:
                return [i, n[diff]]