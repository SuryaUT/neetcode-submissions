class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        n = set(nums)
        longest = 0

        for num in n:
            if not num - 1 in n:
                curr = 1
                while num + curr in n:
                    curr += 1
                longest = max(curr, longest)

        return longest