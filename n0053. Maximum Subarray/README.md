# Maximum Subarray :star:
- 题目地址: [https://leetcode-cn.com/problems/maximum-subarray](https://leetcode-cn.com/problems/maximum-subarray)
- 执行时间: 8 ms 
- 内存消耗: N/A
- 通过日期: 2019-04-13 00:34
## 题目内容
<p>给定一个整数数组 <code>nums</code> ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [-2,1,-3,4,-1,2,1,-5,4],
<strong>输出:</strong> 6
<strong>解释:</strong> 连续子数组 [4,-1,2,1] 的和最大，为 6。
</pre>

<p><strong>进阶:</strong></p>

<p>如果你已经实现复杂度为 O(<em>n</em>) 的解法，尝试使用更为精妙的分治法求解。</p>

## 解法
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN,tmp = 0;
        for(int i : nums)
        {
            tmp += i;
            if(result < tmp)
                result = tmp;
            if(tmp < 0)
                tmp = 0;
        }
        return result;
    }

};

```