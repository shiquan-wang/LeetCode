


class Solution:
    def countBits(self, n : int):
        res = [0]
        for i in range(1, n+1):
            res.append(res[i >> 1] + i % 2)
        return res

s1 = Solution();
print(f"res{s1.countBits(3)}")