# Climbing Stairs :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/climbing-stairs](https://leetcode-cn.com/problems/climbing-stairs)
- ִ��ʱ��: 4 ms 
- �ڴ�����: N/A
- ͨ������: 2019-04-15 00:28
## ��Ŀ����
<p>������������¥�ݡ���Ҫ <em>n</em>�0�2������ܵ���¥����</p>

<p>ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�</p>

<p><strong>ע�⣺</strong>���� <em>n</em> ��һ����������</p>

<p><strong>ʾ�� 1��</strong></p>

<pre><strong>���룺</strong> 2
<strong>�����</strong> 2
<strong>���ͣ�</strong> �����ַ�����������¥����
1.  1 �� + 1 ��
2.  2 ��</pre>

<p><strong>ʾ�� 2��</strong></p>

<pre><strong>���룺</strong> 3
<strong>�����</strong> 3
<strong>���ͣ�</strong> �����ַ�����������¥����
1.  1 �� + 1 �� + 1 ��
2.  1 �� + 2 ��
3.  2 �� + 1 ��
</pre>

## �ⷨ
```cpp
// Author: klinghui @ https://github.com/konglhui/Leetcode
class Solution {
public:
    int climbStairs(int n) {
        int sub = 1;
        if(n == 1)
            return sub;
        int pre = 2;
        if(n == 2)
            return pre;
        for(int i = 2;i< n;i++)
        {
            int tmp = pre;
            pre = pre + sub;
            sub = tmp;
        }
        return pre;
    }
};

```