import math

def res(n):
    re = n
    while n > 1:
        l = int(math.log(n, 2))
        print(l)
        s = 1<<l
        re += (n-s+1)*l
        n = s-1
    return re

print(res(10))