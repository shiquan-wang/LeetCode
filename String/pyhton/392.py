class Solution:
    def isSubsequence(self, s:str, t:str)->bool:
        m = len(s)
        n = len(t)
        i = j =0
        while i<m and j<n:
            if s[i] == t[j]:
                i+=1
            j+=1
        return i==m

s = 'ace'
t = 'abcde'
s1 = Solution()
print(f"result is {s1.isSubsequence(s, t)}")