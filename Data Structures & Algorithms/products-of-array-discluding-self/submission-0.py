class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        res = []
        prod = 1
        pnz = 1
        z = 0
        for num in nums:
            if num != 0:
                pnz *= num
            else:
                z += 1
            prod *= num
        
        for num in nums:
            if num == 0:
                if z > 1:
                    res.append(0)
                else:
                    res.append(pnz)
            else:
                res.append(int(prod/num))
        return res