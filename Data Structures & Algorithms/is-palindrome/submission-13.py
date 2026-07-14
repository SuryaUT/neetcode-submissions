class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        letters_only = ""
        for c in s:
            if c.isalnum():
                letters_only += c.lower()

        return letters_only == letters_only[::-1]