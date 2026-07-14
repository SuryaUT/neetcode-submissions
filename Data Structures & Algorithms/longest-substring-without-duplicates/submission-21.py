class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == "":
            return 0

        win = set()
        win.add(s[0])

        l = 0
        r = 1
        maxLen = 1

        while r < len(s):
            if s[r] in win:
                maxLen = max(maxLen, len(win))
                while s[l] != s[r]:
                    win.remove(s[l])
                    l += 1
                win.remove(s[l])
                l += 1
            win.add(s[r])
            r += 1

        maxLen = max(maxLen, len(win))
        return maxLen

