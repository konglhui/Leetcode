# Two Sum :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/two-sum](https://leetcode-cn.com/problems/two-sum)
- ִ��ʱ��: 112 ms 
- �ڴ�����: N/A
- ͨ������: 2018-09-25 21:57
## ��Ŀ����
<p>����һ���������� <code>nums</code>�0�2��һ��Ŀ��ֵ <code>target</code>�������ڸ��������ҳ���ΪĿ��ֵ���ǁ0�2<strong>����</strong>�0�2���������������ǵ������±ꡣ</p>

<p>����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ�ز���ʹ�����顣</p>



<p><strong>ʾ��:</strong></p>

<pre>���� nums = [2, 7, 11, 15], target = 9

��Ϊ nums[<strong>0</strong>] + nums[<strong>1</strong>] = 2 + 7 = 9
���Է��� [<strong>0, 1</strong>]
</pre>

## �ⷨ
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