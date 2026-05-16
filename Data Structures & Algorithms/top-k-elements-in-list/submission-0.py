class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        nmap = defaultdict(int)
        count = [[] for i in range(len(nums) + 1)]
        for num in nums:
            nmap[num] += 1
        for num, freq in nmap.items():
            count[freq].append(num)

        res = []
        for i in range(len(count)-1, -1, -1):
            for num in count[i]:
                res.append(num)
                if len(res) == k:
                    return res
