# Sqrt(x) :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/sqrtx](https://leetcode-cn.com/problems/sqrtx)
- ִ��ʱ��: 16 ms 
- �ڴ�����: N/A
- ͨ������: 2019-02-14 21:53
## ��Ŀ����
<p>ʵ�ց0�2<code>int sqrt(int x)</code>�0�2������</p>

<p>���㲢���؁0�2<em>x</em>�0�2��ƽ���������Ё0�2<em>x </em>�ǷǸ�������</p>

<p>���ڷ������������������ֻ���������Ĳ��֣�С�����ֽ�����ȥ��</p>

<p><strong>ʾ�� 1:</strong></p>

<pre><strong>����:</strong> 4
<strong>���:</strong> 2
</pre>

<p><strong>ʾ�� 2:</strong></p>

<pre><strong>����:</strong> 8
<strong>���:</strong> 2
<strong>˵��:</strong> 8 ��ƽ������ 2.82842..., 
�0�2    ���ڷ���������������С�����ֽ�����ȥ��
</pre>

## �ⷨ
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
 * Compute and return the square root of x, where�0�2x�0�2is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type�0�2is an integer, the decimal digits are truncated and
 * only the integer part of the result�0�2is returned.
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