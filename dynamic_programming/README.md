[1143_最长子序列](https://github.com/shiquan-wang/LeetCode/blob/master/String/cpp/1143_longest_common_subsequence.cpp)  
**第一步**dp数组含义：dp\[i\]\[j\] 是s1\[i\]与s2\[j\]的最大子序列数目，
![](https://github.com/shiquan-wang/pictures/blob/master/leetcode/long_common_subsequence.png)  
**第二步**base case:  
i=0时， 对于任意0<=j<=n,dp\[0\]\[j\]=0; j=0时同理  
**第三步**状态转移方程：  
求 s1 和 s2 的最长公共子序列，不妨称这个子序列为 lcs。那么对于 s1 和 s2 中的每个字符，有什么选择？很简单，两种选择，要么在 lcs 中，要么不在。  
![](https://github.com/shiquan-wang/pictures/blob/master/leetcode/lcs.png)  
如果某个字符应该在 lcs 中，那么这个字符肯定同时存在于 s1 和 s2 中，因为 lcs 是最长公共子序列  
用两个指针 i 和 j 从后往前遍历 s1 和 s2，如果 s1\[i\]==s2\[j\]，那么这个字符一定在 lcs 中；否则的话，s1\[i\] 和 s2\[j\] 这两个字符至少有一个不在 lcs 中，需要丢弃一个 
![](https://github.com/shiquan-wang/pictures/blob/master/leetcode/dp_string.png)  
dp 在 string中的问题，

