# Maximum Subarray :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/maximum-subarray](https://leetcode-cn.com/problems/maximum-subarray)
- ִ��ʱ��: 8 ms 
- �ڴ�����: N/A
- ͨ������: 2019-04-13 00:34
## ��Ŀ����
<p>����һ���������� <code>nums</code>�0�2���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�</p>

<p><strong>ʾ��:</strong></p>

<pre><strong>����:</strong> [-2,1,-3,4,-1,2,1,-5,4],
<strong>���:</strong> 6
<strong>����:</strong>�0�2����������0�2[4,-1,2,1] �ĺ����Ϊ�0�26��
</pre>

<p><strong>����:</strong></p>

<p>������Ѿ�ʵ�ָ��Ӷ�Ϊ O(<em>n</em>) �Ľⷨ������ʹ�ø�Ϊ����ķ��η���⡣</p>

## �ⷨ
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