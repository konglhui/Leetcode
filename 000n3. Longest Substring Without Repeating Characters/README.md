# Longest Substring Without Repeating Characters :star::star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/longest-substring-without-repeating-characters](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters)
- ִ��ʱ��: 20 ms 
- �ڴ�����: N/A
- ͨ������: 2019-04-21 15:50
## ��Ŀ����
<p>����һ���ַ����������ҳ����в������ظ��ַ��ā0�2<strong>��Ӵ��0�2</strong>�ĳ��ȡ�</p>

<p><strong>ʾ���0�21:</strong></p>

<pre><strong>����: </strong>"abcabcbb"
<strong>���: </strong>3 
<strong>����:</strong> ��Ϊ���ظ��ַ�����Ӵ��� <code>"abc"��������</code>����Ϊ 3��
</pre>

<p><strong>ʾ�� 2:</strong></p>

<pre><strong>����: </strong>"bbbbb"
<strong>���: </strong>1
<strong>����: </strong>��Ϊ���ظ��ַ�����Ӵ��� <code>"b"</code>�������䳤��Ϊ 1��
</pre>

<p><strong>ʾ�� 3:</strong></p>

<pre><strong>����: </strong>"pwwkew"
<strong>���: </strong>3
<strong>����: </strong>��Ϊ���ظ��ַ�����Ӵ��ǁ0�2<code>"wke"</code>�������䳤��Ϊ 3��
�0�2    ��ע�⣬��Ĵ𰸱����� <strong>�Ӵ� </strong>�ĳ��ȣ�<code>"pwke"</code>�0�2��һ��<em>�����У�</em>�����Ӵ���
</pre>

## �ⷨ
```cpp
// Author: klinghui @ https://github.com/konglhui/Leetcode
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vmap( 256,-1);
        int maxLength = 0;
        int start = -1;
        int _size = s.size();
        for(int i = 0;i < _size; i++)
        {
            if(vmap[s[i]]  != -1)
                if(start < vmap[s[i]])
                    start = vmap[s[i]];
            vmap[s[i]] = i;
            
            maxLength = max(maxLength,i - start);
        }
        return maxLength;
    }
};

```