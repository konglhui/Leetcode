# Sqrt(x) :star:
- 题目地址: [https://leetcode-cn.com/problems/sqrtx](https://leetcode-cn.com/problems/sqrtx)
- 执行时间: 16 ms 
- 内存消耗: N/A
- 通过日期: 2019-02-14 21:53
## 题目内容
<p>实现 <code>int sqrt(int x)</code> 函数。</p>

<p>计算并返回 <em>x</em> 的平方根，其中 <em>x </em>是非负整数。</p>

<p>由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 4
<strong>输出:</strong> 2
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 8
<strong>输出:</strong> 2
<strong>说明:</strong> 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
</pre>

## 解法
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (30.48%)
 * Total Accepted:    323.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */
class Solution {
public:
    int mySqrt(int x) {
/*        int left = 0;
        int right = x + 1;
        while(left<right)
        {
            int val = left + (right - left) / 2;
            if(val*val > x)
                right = val;
            else
                left = val + 1;
        }
        return left - 1;*/
        return (int)sqrt(x); 
    }
};


```