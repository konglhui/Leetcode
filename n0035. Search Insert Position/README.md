# Search Insert Position :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/search-insert-position](https://leetcode-cn.com/problems/search-insert-position)
- ִ��ʱ��: 8 ms 
- �ڴ�����: N/A
- ͨ������: 2019-04-12 00:39
## ��Ŀ����
<p>����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�</p>

<p>����Լ������������ظ�Ԫ�ء�</p>

<p><strong>ʾ�� 1:</strong></p>

<pre><strong>����:</strong> [1,3,5,6], 5
<strong>���:</strong> 2
</pre>

<p><strong>ʾ���0�22:</strong></p>

<pre><strong>����:</strong> [1,3,5,6], 2
<strong>���:</strong> 1
</pre>

<p><strong>ʾ�� 3:</strong></p>

<pre><strong>����:</strong> [1,3,5,6], 7
<strong>���:</strong> 4
</pre>

<p><strong>ʾ�� 4:</strong></p>

<pre><strong>����:</strong> [1,3,5,6], 0
<strong>���:</strong> 0
</pre>

## �ⷨ
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0 ,_size = nums.size();i<_size;i++)
        {
            if(target <= nums[i])
                    return i;
 
        }
        return nums.size();
    }
};

```