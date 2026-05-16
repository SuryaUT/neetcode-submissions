class Solution:
    def maxArea(self, heights: List[int]) -> int:
        maxA = 0
        l = 0
        r = len(heights) - 1

        while l < r:
            area = (r - l)*min(heights[r], heights[l])
            maxA = max(area, maxA)
            if heights[r] < heights[l]:
                r -= 1
            elif heights[l] < heights[r]:
                l += 1
            else:
                if heights[r - 1] < heights[l + 1]:
                    l += 1
                elif heights[l + 1] < heights[r - 1]:
                    r-= 1
                else:
                    l += 1

        return maxA
