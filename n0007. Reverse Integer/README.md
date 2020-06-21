# Reverse Integer :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/reverse-integer](https://leetcode-cn.com/problems/reverse-integer)
- ִ��ʱ��: 12 ms 
- �ڴ�����: N/A
- ͨ������: 2018-09-25 22:49
## ��Ŀ����
<p>����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��</p>

<p><strong>ʾ���0�21:</strong></p>

<pre><strong>����:</strong> 123
<strong>���:</strong> 321
</pre>

<p><strong>�0�2ʾ�� 2:</strong></p>

<pre><strong>����:</strong> -123
<strong>���:</strong> -321
</pre>

<p><strong>ʾ�� 3:</strong></p>

<pre><strong>����:</strong> 120
<strong>���:</strong> 21
</pre>

<p><strong>ע��:</strong></p>

<p>�������ǵĻ���ֻ�ܴ洢���� 32 λ���з���������������ֵ��ΧΪ�0�2[�6�12<sup>31</sup>,�0�2 2<sup>31�0�2</sup>�6�1 1]�������������裬�����ת�����������ô�ͷ��� 0��</p>

## �ⷨ
```cpp
// Author: klinghui @ https://github.com/konglhui/Leetcode
class Solution {
public:
    int reverse(int x) 
    {
        int rev = 0;
        while (x) 
        {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

```