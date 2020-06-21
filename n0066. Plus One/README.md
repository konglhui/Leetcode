# Plus One :star:
- 题目地址: [https://leetcode-cn.com/problems/plus-one](https://leetcode-cn.com/problems/plus-one)
- 执行时间: 4 ms 
- 内存消耗: N/A
- 通过日期: 2019-04-14 03:02
## 题目内容
<p>给定一个由<strong>整数</strong>组成的<strong>非空</strong>数组所表示的非负整数，在该数的基础上加一。</p>

<p>最高位数字存放在数组的首位， 数组中每个元素只存储<strong>单个</strong>数字。</p>

<p>你可以假设除了整数 0 之外，这个整数不会以零开头。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [1,2,3]
<strong>输出:</strong> [1,2,4]
<strong>解释:</strong> 输入数组表示数字 123。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [4,3,2,1]
<strong>输出:</strong> [4,3,2,2]
<strong>解释:</strong> 输入数组表示数字 4321。
</pre>

## 解法
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        for(;i > -1 ;i--)
        {
            digits[i] ++;
            if(digits[i] > 9)
                digits[i] = 0;
            else
                break;
        }
        if(i == -1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

```