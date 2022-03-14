from collections import defaultdict
from email.policy import default
from functools import reduce
from itertools import product
from typing import List


class Solution:
    def maxProduct(self, words : List[str]) -> int:
        #计算一个字符串的二进制表示
        def get_mask(word : str) -> int:
            mask = 0
            for char in word:
                mask |= (1 << ord(char) - ord('a'))
                # ord Return the Unicode code point for a one-character string
            return mask

        masks = []

        #得到masks数组
        for word in words:
            masks.append(get_mask(word))
        
        res = 0
        #另一种写法 product(A,B)返回A B中元素组成的笛卡尔积元组
        #例如 product('ab', range(3)) 
        # --> ('a',0) ('a',1) ('a',2) ('b',0) ('b',1) ('b',2) 
        # product((0,1), (0,1), (0,1)) --> (0,0,0) (0,0,1) (0,1,0) 
        # (0,1,1) (1,0,0) 
        #for x, y in product(masks, repeat=2)
        for i in range(len(masks)):
            for j in range(i+1, len(masks)):
                if masks[i] & masks[j] == 0:
                    res = max(res, len(words[i]) * len(words[j]))
        
        return res

s1 = Solution()
print(f"s1 : {s1.maxProduct(['a', 'aa', 'aaa', 'aaaa'])}")

        