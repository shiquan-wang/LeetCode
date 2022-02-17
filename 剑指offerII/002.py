
class Solution:
    def addBinary(self, a, b) -> str:
        return '{0:b}'.format(int(a, 2) + int(b, 2))

s1 = Solution()
a = "11"
b = "10"
print(s1.addBinary(a="11", b="10"))
# print(s1.addBinary(a, b))