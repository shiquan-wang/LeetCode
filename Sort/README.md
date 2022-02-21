# 排序算法

排序方法 | 时间复杂度 | 时间复杂度（最好） | 时间复杂度（最坏）| 空间复杂度 | 稳定性
:-:|:-:|:-:|:-:|:-:|:-:
冒泡排序 | O(n^2)    | O(n)      | O(n^2)    | O(1)  | 稳定
选择排序 | O(n^2)    | O(n^2)    | O(n^2)    | O(1)  | 不稳定
插入排序 | O(n^2)    | O(n)      | O(n^2)    | O(1)  | 稳定
希尔排序 | O(n^2) ~ O(nlog2n) | O(n) | O(n^2) | O(1) | 不稳定
归并排序 | O(nlog2n) | O(nlog2n) | O(nlog2n) | O(n)  | 稳定
快速排序 | O(nlog2n) | O(nlog2n) | O(n^2) | O(nlog2n)| 不稳定
堆排序   | O(nlog2n) | O(nlog2n) | O(nlog2n) | O(1)  | 不稳定
计数排序 | O(n+k)    | O(n+k)    | O(n+k)    | O(n+k)| 稳定
桶排序   | O(n+k)    | O(n+k)    | O(n^2)    | O(n+k)| 稳定
基数排序 | O(n\*k)   | O(n\*k)   | O(n*k)    | O(n+k)| 稳定
## [冒泡排序]()
时间复杂度O（n^2） 稳定的排序

算法描述：
```markdown
每次冒泡趟都是将最大的元素放在最后
对于n个元素的数组，需要进行n-1趟排序

第i趟排序
从开始比较相邻元素，将较大的元素放在后边，一直到第n-i-1个元素, 因为后面的元素已经有序了。
```
## [选择排序]()
时间复杂度O(n^2) 不稳定排序，（5， 5*， 2）——> (2, 5*, 5)

算法描述：
```markdown
每次选择趟都是选择出最小或最大元素，放在有序区的最后，
n个元素共需要n-1次选择排序，第i次排序有序区是0 - i-1,

初始有序序列[] 初始无序序列 [0 - n-1]
第i趟排序, 有序序列[0 - i-1], 初始无序序列[i - n-1]
遍历无序序列，寻找到序列中最小的元素，记录下标index，最后交换index与i的数值
```

## [插入排序]()
时间复杂度O(n^2) 稳定排序

算法描述：
```markdown
构建有序序列后，将未排序序列插入到有序序列中
n个元素共需要n-1次插入操作

第i次排序， 有序区为[0 - i-1], 
有序区从后向前遍历，如果新元素大于遍历元素，那么将遍历元素后移，否则将新元素插入该位置
```

## [希尔排序]()
时间复杂度O(n^2) - O(nlog2n) 不稳定排序(5, 5*, 2)增量h=[1, 2]时,排序后(2, 5*, 5)

算法描述：
```markdown
可以看做是分组插入排序， 首先选择一组增量序列比如[1, 3, 7, ......, 2^k-1],
然后按照由大到小的顺序取增量序列，按照这个间隔来进行划分组，组内进行插入排序，
逐渐减少间隔的大小，最后间隔为1排序后结束
```
```c++
while(h > 0){
    for(int i = 0; i < nums.size(); i += h){
        index = i - h, temp = nums[i];
        while(index >= 0 && nums[index] > temp){
            nums[index] = nums[index + h];
            index -= h;
        }
        nums[index + h] = temp;
    }
    h /= 3;
}

```

## [归并排序]()

时间复杂度O(nlog2n) 稳定排序