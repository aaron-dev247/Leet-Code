class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False
        
        wordCount = {}
        for i in range(len(s)):

            if s[i] not in wordCount:
                wordCount[s[i]] = 0

            if t[i] not in wordCount:
                wordCount[t[i]] = 0

            wordCount[s[i]] += 1
            wordCount[t[i]] -= 1
        
        for count in wordCount.values():
            if count != 0:
                return False
        
        return True

s = Solution()
s.isAnagram("anagram", "nagaram")