# ZigZag Conversion :star::star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/zigzag-conversion](https://leetcode-cn.com/problems/zigzag-conversion)
- ִ��ʱ��: 12 ms 
- �ڴ�����: 8.2 MB
- ͨ������: 2020-05-22 12:45
## ��Ŀ����
<p>��һ�������ַ������ݸ������������Դ������¡������ҽ��Ё0�2Z �������С�</p>

<p>���������ַ���Ϊ <code>"LEETCODEISHIRING"</code>�0�2����Ϊ 3 ʱ���������£�</p>

<pre>L   C   I   R
E T O E S I I G
E   D   H   N
</pre>

<p>֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺<code>"LCIRETOESIIGEDHN"</code>��</p>

<p>����ʵ��������ַ�������ָ�������任�ĺ�����</p>

<pre>string convert(string s, int numRows);</pre>

<p><strong>ʾ���0�21:</strong></p>

<pre><strong>����:</strong> s = "LEETCODEISHIRING", numRows = 3
<strong>���:</strong> "LCIRETOESIIGEDHN"
</pre>

<p><strong>ʾ���0�22:</strong></p>

<pre><strong>����:</strong> s = "LEETCODEISHIRING", numRows =�0�24
<strong>���:</strong>�0�2"LDREOEIIECIHNTSG"
<strong>����:</strong>

L     D     R
E   O E   I I
E C   I H   N
T     S     G</pre>

## �ⷨ
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    string convert(string s, int numRows) 
    {
        if(numRows == 1)
            return s;
        string result;
        const unsigned int size = s.size();
        const unsigned int half_length = numRows -1;
        const unsigned int ont_length = half_length * 2;
        const unsigned int time = size / ont_length + 1;
        for(unsigned int i = 0; i < numRows;i++)
        {
            for(unsigned int j = 0; j < time;j++)
            {
                const unsigned int start = ont_length *j;
                const unsigned int first = start + i;

                if(size <= first)
                    continue;
                result.push_back(s[first]);

                if(i != 0 && i != numRows - 1)
                {
                    unsigned int second = start + ont_length - i ;
                    if(size > second)
                        result.push_back(s[second]);
                }
            }
        }
        return result;
    }
};

```