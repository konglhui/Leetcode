# Length of Last Word :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/length-of-last-word](https://leetcode-cn.com/problems/length-of-last-word)
- ִ��ʱ��: 4 ms 
- �ڴ�����: N/A
- ͨ������: 2019-04-13 01:04
## ��Ŀ����
<p>����һ����������Сд��ĸ�Ϳո�0�2<code>' '</code>�0�2���ַ��� <code>s</code>�����������һ�����ʵĳ��ȡ�����ַ����������ҹ�����ʾ����ô���һ�����ʾ��������ֵĵ��ʡ�</p>

<p>������������һ�����ʣ��뷵�� 0�0�2��</p>

<p><strong>˵����</strong>һ��������ָ������ĸ��ɡ��������κοո��ַ��� <strong>������ַ���</strong>��</p>



<p><strong>ʾ��:</strong></p>

<pre><strong>����:</strong> "Hello World"
<strong>���:</strong> 5
</pre>

## �ⷨ
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    int lengthOfLastWord(string s) {
        int _size = s.size();
        int result = 0;
        for(int i = _size - 1; i > -1;--i)
        {
            if(result == 0 && s[i] == ' ')
                continue;
            if(s[i] == ' ')
                break;
            result++;
        }
        return result;
    }
};

```