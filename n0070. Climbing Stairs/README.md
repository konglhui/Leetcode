# Climbing Stairs :star:
- 题目地址: [https://leetcode-cn.com/problems/climbing-stairs](https://leetcode-cn.com/problems/climbing-stairs)
- 执行时间: 4 ms 
- 内存消耗: N/A
- 通过日期: 2019-04-15 00:28
## 题目内容
<p>假设你正在爬楼梯。需要 <em>n</em> 阶你才能到达楼顶。</p>

<p>每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？</p>

<p><strong>注意：</strong>给定 <em>n</em> 是一个正整数。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong> 2
<strong>输出：</strong> 2
<strong>解释：</strong> 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong> 3
<strong>输出：</strong> 3
<strong>解释：</strong> 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
</pre>

## 解法
```cpp
// Author: klinghui @ https://github.com/konglhui/Leetcode
class Solution {
public:
    int climbStairs(int n) {
        int sub = 1;
        if(n == 1)
            return sub;
        int pre = 2;
        if(n == 2)
            return pre;
        for(int i = 2;i< n;i++)
        {
            int tmp = pre;
            pre = pre + sub;
            sub = tmp;
        }
        return pre;
    }
};

```