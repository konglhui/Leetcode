# Implement strStr() :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/implement-strstr](https://leetcode-cn.com/problems/implement-strstr)
- ִ��ʱ��: 4 ms 
- �ڴ�����: N/A
- ͨ������: 2019-04-12 00:19
## ��Ŀ����
<p>ʵ�ց0�2<a href="https://baike.baidu.com/item/strstr/811469" target="_blank">strStr()</a>�0�2������</p>

<p>����һ���0�2haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻؁0�2 <strong>-1</strong>��</p>

<p><strong>ʾ�� 1:</strong></p>

<pre><strong>����:</strong> haystack = "hello", needle = "ll"
<strong>���:</strong> 2
</pre>

<p><strong>ʾ�� 2:</strong></p>

<pre><strong>����:</strong> haystack = "aaaaa", needle = "bba"
<strong>���:</strong> -1
</pre>

<p><strong>˵��:</strong></p>

<p>���0�2<code>needle</code>�0�2�ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�����һ���������кܺõ����⡣</p>

<p>���ڱ�����ԣ����0�2<code>needle</code>�0�2�ǿ��ַ���ʱ����Ӧ������ 0 ������C���Եā0�2<a href="https://baike.baidu.com/item/strstr/811469" target="_blank">strstr()</a>�0�2�Լ� Java�ā0�2<a href="https://docs.oracle.com/javase/7/docs/api/java/lang/String.html#indexOf(java.lang.String)" target="_blank">indexOf()</a>�0�2���������</p>

## �ⷨ
```cpp
// Author: klinghui @ https://github.com/konglhui/Leetcode
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;

        for(int i = 0, _size = haystack.size(); i< _size;i++)
        {
            if(haystack[i] == needle[0])
                if(judgeStr(haystack,needle,i))
                    return i;
        }
        return -1;

    }
    
    bool judgeStr(string &stack,string &needle,int inputI)
    {
        if(stack.size() - inputI < needle.size())
            return false;
        
        for(int i = 1,_size = needle.size();i < _size;i++)
        {
            if(stack[inputI + i] != needle[i])
                return false;
        }
        return true;
    }
};

```