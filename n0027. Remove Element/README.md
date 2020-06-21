# Remove Element :star:
- 题目地址: [https://leetcode-cn.com/problems/remove-element](https://leetcode-cn.com/problems/remove-element)
- 执行时间: 4 ms 
- 内存消耗: N/A
- 通过日期: 2019-04-11 00:15
## 题目内容
<p>给你一个数组 <em>nums </em>和一个值 <em>val</em>，你需要 <strong><a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank">原地</a></strong> 移除所有数值等于 <em>val </em>的元素，并返回移除后数组的新长度。</p>

<p>不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 <strong><a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank">原地 </a>修改输入数组</strong>。</p>

<p>元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。</p>



<p><strong>示例 1:</strong></p>

<pre>给定 <em>nums</em> = <strong>[3,2,2,3]</strong>, <em>val</em> = <strong>3</strong>,

函数应该返回新的长度 <strong>2</strong>, 并且 <em>nums </em>中的前两个元素均为 <strong>2</strong>。

你不需要考虑数组中超出新长度后面的元素。
</pre>

<p><strong>示例 2:</strong></p>

<pre>给定 <em>nums</em> = <strong>[0,1,2,2,3,0,4,2]</strong>, <em>val</em> = <strong>2</strong>,

函数应该返回新的长度 <strong><code>5</code></strong>, 并且 <em>nums </em>中的前五个元素为 <strong><code>0</code></strong>, <strong><code>1</code></strong>, <strong><code>3</code></strong>, <strong><code>0</code></strong>, <strong>4</strong>。

注意这五个元素可为任意顺序。

你不需要考虑数组中超出新长度后面的元素。
</pre>



<p><strong>说明:</strong></p>

<p>为什么返回数值是整数，但输出的答案是数组呢?</p>

<p>请注意，输入数组是以<strong>「引用」</strong>方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。</p>

<p>你可以想象内部操作如下:</p>

<pre>// <strong>nums</strong> 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
int len = removeElement(nums, val);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中<strong> 该长度范围内</strong> 的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
</pre>

## 解法
```cpp
// Author: klinghui @ https://github.com/konglhui/Leetcode
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int size = nums.size();
        int times = 0;
        int i = 0;
        int ____size = size - 1 ;
        while(i + times < size)
        {
            if(nums[____size - times] == val)
            {
                times++;
                continue;
            }
            if(nums[i] == val)
            {
                swapNums(nums[____size - times],nums[i]);
                times++;
                continue;
            }
            i++;
        }
        return size - times;
    }
    
    void swapNums(int & a,int & b)
    {
        int c = a;
        a = b;
        b = c;
    }

};

```