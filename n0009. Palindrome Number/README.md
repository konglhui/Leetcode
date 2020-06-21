# Palindrome Number :star:
- 题目地址: [https://leetcode-cn.com/problems/palindrome-number](https://leetcode-cn.com/problems/palindrome-number)
- 执行时间: 196 ms 
- 内存消耗: N/A
- 通过日期: 2018-09-26 00:30
## 题目内容
<p>判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 121
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> -121
<strong>输出:</strong> false
<strong>解释:</strong> 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> 10
<strong>输出:</strong> false
<strong>解释:</strong> 从右向左读, 为 01 。因此它不是一个回文数。
</pre>

<p><strong>进阶:</strong></p>

<p>你能不将整数转为字符串来解决这个问题吗？</p>

## 解法
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<10 && x>=0) 
            return true;
        if(x < 0 || x%10 == 0) 
            return false;

        int judge = 0;
        while(x > judge)
        {
            judge =judge * 10 +  x%10;
            x /= 10;
        }
        
        return judge == x || x == judge/10;
    }
};

```