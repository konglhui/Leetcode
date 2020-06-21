# Merge Sorted Array :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/merge-sorted-array](https://leetcode-cn.com/problems/merge-sorted-array)
- ִ��ʱ��: 4 ms 
- �ڴ�����: N/A
- ͨ������: 2019-04-21 14:33
## ��Ŀ����
<p>��������������������0�2<em>nums1 </em>�� <em>nums2</em>�����㽫 <em>nums2 </em>�ϲ����0�2<em>nums1�0�2</em>��<em>��</em>ʹ <em>nums1 </em>��Ϊһ���������顣</p>



<p><strong>˵��:</strong></p>

<ul>
	<li>��ʼ���0�2<em>nums1</em> �� <em>nums2</em> ��Ԫ�������ֱ�Ϊ�0�2<em>m</em> �� <em>n </em>��</li>
	<li>����Լ���0�2<em>nums1�0�2</em>���㹻�Ŀռ䣨�ռ��С���ڻ���ځ0�2<em>m + n</em>�������� <em>nums2</em> �е�Ԫ�ء�</li>
</ul>



<p><strong>ʾ��:</strong></p>

<pre><strong>����:</strong>
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

<strong>���:</strong>�0�2[1,2,2,3,5,6]</pre>

## �ⷨ
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