class Solution:
    def freq(s: str) -> tuple:
        arr = [0]*26
        for c in s:
            arr[ord(c)-ord('a')] += 1

        return tuple(arr)
        
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        smap = defaultdict(list)

        for s in strs:
            smap[Solution.freq(s)].append(s)
        
        return list(smap.values())
