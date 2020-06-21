# Merge Sorted Array :star:
- 题目地址: [https://leetcode-cn.com/problems/merge-sorted-array](https://leetcode-cn.com/problems/merge-sorted-array)
- 执行时间: 4 ms 
- 内存消耗: N/A
- 通过日期: 2019-04-21 14:33
## 题目内容
<p>给你两个有序整数数组 <em>nums1 </em>和 <em>nums2</em>，请你将 <em>nums2 </em>合并到 <em>nums1 </em>中<em>，</em>使 <em>nums1 </em>成为一个有序数组。</p>



<p><strong>说明:</strong></p>

<ul>
	<li>初始化 <em>nums1</em> 和 <em>nums2</em> 的元素数量分别为 <em>m</em> 和 <em>n </em>。</li>
	<li>你可以假设 <em>nums1 </em>有足够的空间（空间大小大于或等于 <em>m + n</em>）来保存 <em>nums2</em> 中的元素。</li>
</ul>



<p><strong>示例:</strong></p>

<pre><strong>输入:</strong>
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

<strong>输出:</strong> [1,2,2,3,5,6]</pre>

## 解法
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (n != 0 )
        {
            if(m == 0)
            {
                nums1[n-1] = nums2[n-1];
                n--;
                continue;
            }
            if(nums1[m-1] > nums2[n-1])
            {
                nums1[m + n - 1] = nums1[m-1];
                m--;
            }
            else
            {
                nums1[m + n - 1] = nums2[n-1];
                n--;
            }
        }
    }
};

```