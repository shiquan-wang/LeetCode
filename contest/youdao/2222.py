import collections

class Solution:
    def res(self, s: str):
        n = len(s)
        zc, oc, tc = 0, 0, 0
        res = 0
        map = collections.defaultdict(int)
        map[(0, 0)] = 1
        for i in range(n):
            if s[i] == 'r':
                zc += 1
            elif s[i] == 'e':
                oc += 1
            else:
                tc += 1
            tmp = (zc - oc, zc - tc)
            res += map[tmp]
            map[tmp] += 1
        print(res)

s = input()
s1 = Solution()
s1.res(s)