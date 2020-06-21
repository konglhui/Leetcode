# Palindrome Number :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/palindrome-number](https://leetcode-cn.com/problems/palindrome-number)
- ִ��ʱ��: 196 ms 
- �ڴ�����: N/A
- ͨ������: 2018-09-26 00:30
## ��Ŀ����
<p>�ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������</p>

<p><strong>ʾ�� 1:</strong></p>

<pre><strong>����:</strong> 121
<strong>���:</strong> true
</pre>

<p><strong>ʾ���0�22:</strong></p>

<pre><strong>����:</strong> -121
<strong>���:</strong> false
<strong>����:</strong> �������Ҷ�, Ϊ -121 �� ���������, Ϊ 121- �����������һ����������
</pre>

<p><strong>ʾ�� 3:</strong></p>

<pre><strong>����:</strong> 10
<strong>���:</strong> false
<strong>����:</strong> ���������, Ϊ 01 �����������һ����������
</pre>

<p><strong>����:</strong></p>

<p>���ܲ�������תΪ�ַ�����������������</p>

## �ⷨ
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<10 && x>=0) 
            return true;
        if(x < 0 || x%10 == 0) 
            return false;

        int judge = 0;
        while(x > judge)
        {
            judge =judge * 10 +  x%10;
            x /= 10;
        }
        
        return judge == x || x == judge/10;
    }
};

```