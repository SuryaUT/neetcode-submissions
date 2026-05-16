class Solution:
    def isPalindrome(self, s: str) -> bool:
        length = len(s)
        cur = 0
        end = length - 1

        while end > cur:
            while end > cur and not s[end].isalnum():
                end -= 1
            while end > cur and not s[cur].isalnum():
                cur += 1
            if s[cur].lower() != s[end].lower():
                return False
            end -= 1
            cur += 1
        return True
