from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        res = defaultdict(list)
        for s in strs:
            hist = [0]*26
            for c in s:
                hist[ord(c)-ord('a')] += 1
            res[tuple(hist)].append(s)

        return list(res.values())