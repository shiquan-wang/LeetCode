# import math
# from typing import List

# def distance(a, b):
#     return math.sqrt(pow((b[1] - a[1]), 2) + pow((b[0] - a[0]), 2))

def mean(a):
    x = 0.0
    y = 0.0
    for i in range(len(a)):
        x =  x+a[0]
        y =  y+a[1]
    return x/len(a), y/len(a)

# a = [3, 1, 0]
# b = [1, 0]
# print(distance(a, b))
# print(math.sqrt(5))
# print(min(a))
# print(mean(a))

# position = [[1.5,2.1], [0.8,2.1], [1.3,2.1], [110.5,260.6], [21.7, 32.8],[130.9,150.8],[32.6,40.7],[41.5,24.7]]
# for sample in position:
#     print(sample)

# def min_idx(a):
#     min = a[0]
#     idx = 0
#     for i in range(len(a)):
#         if a[i] < min:
#             min = a[i]
#             idx = i
#     return idx

a = [3, 1, 2]
x, y = mean(a)
print(x, y)
