class Solution:
    def divide(self, a : int, b : int)->int:
        res = 0;
        flag = False if(a > 0 and b > 0) or (a < 0 and b < 0) else True
        a, b = abs(a), abs(b)

        def calc(x, y):
            n = 1;
            while x > y << 1:
                y << 1
                n << 1
            return n, y
        
        while a >= b:
            cnt, val = calc(a, b)
            res += cnt
            a -= val
        
        res = -res if flag else res
        return res - 1 if res >= 2**31 else res