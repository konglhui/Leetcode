# Plus One :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/plus-one](https://leetcode-cn.com/problems/plus-one)
- ִ��ʱ��: 4 ms 
- �ڴ�����: N/A
- ͨ������: 2019-04-14 03:02
## ��Ŀ����
<p>����һ����<strong>����</strong>��ɵ�<strong>�ǿ�</strong>��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��</p>

<p>���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢<strong>����</strong>���֡�</p>

<p>����Լ���������� 0 ֮�⣬��������������㿪ͷ��</p>

<p><strong>ʾ���0�21:</strong></p>

<pre><strong>����:</strong> [1,2,3]
<strong>���:</strong> [1,2,4]
<strong>����:</strong> ���������ʾ���� 123��
</pre>

<p><strong>ʾ���0�22:</strong></p>

<pre><strong>����:</strong> [4,3,2,1]
<strong>���:</strong> [4,3,2,2]
<strong>����:</strong> ���������ʾ���� 4321��
</pre>

## �ⷨ
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        for(;i > -1 ;i--)
        {
            digits[i] ++;
            if(digits[i] > 9)
                digits[i] = 0;
            else
                break;
        }
        if(i == -1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

```