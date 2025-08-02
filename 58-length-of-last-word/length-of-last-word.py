class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()  # remove leading/trailing spaces
        i = -1

        while i >= -len(s) and s[i] != " ":
            i -= 1
        
        return len(s[i + 1:])
