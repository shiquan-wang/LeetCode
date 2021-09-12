# 回溯算法
##
### 组合问题
* 77 组合
* 216 combination sum ||| 组合总和 （选择k个集合中数字使得sum等于target
* 17 letter combinations of phone number
* 39 combination sum 可以无限次的选择集合中的数字
* 40 combination sum || 集合中每个数字只能使用一次,但是集合中数字有重复
### 分割问题
* 131 分割回文字符串
* 93 复原ip地址 *有时间再看看*

### 子集 
\*与组合，分割问题区别在于 子集问题求的是所有节点，组合问题求的是叶子节点，所以res.push_back()时机不一样，前者是每次递归时进行，后者是在终止条件处执行
* 78 子集 
* 90 子集2（nums中存在重复数字
* 491 递增子序列（看一看，和90类似，去重复看一下
### 排列
* 46 全排列(nums 不含重复数字)
* 47 permutations2 全排列2(nums 包含重复数字)
* 332 (未完成)
### 棋盘问题
* 51 N皇后

### others
* 491 递增子序列
* 