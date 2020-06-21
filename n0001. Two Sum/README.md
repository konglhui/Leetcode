# Two Sum :star:
- 题目地址: [https://leetcode-cn.com/problems/two-sum](https://leetcode-cn.com/problems/two-sum)
- 执行时间: 112 ms 
- 内存消耗: N/A
- 通过日期: 2018-09-25 21:57
## 题目内容
<p>给定一个整数数组 <code>nums</code> 和一个目标值 <code>target</code>，请你在该数组中找出和为目标值的那 <strong>两个</strong> 整数，并返回他们的数组下标。</p>

<p>你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。</p>



<p><strong>示例:</strong></p>

<pre>给定 nums = [2, 7, 11, 15], target = 9

因为 nums[<strong>0</strong>] + nums[<strong>1</strong>] = 2 + 7 = 9
所以返回 [<strong>0, 1</strong>]
</pre>

## 解法
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size()-1; ++i)
        {
            for(int j = i+1; j <nums.size();++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    return {i,j};
                }
            }
        }
    }
};

```