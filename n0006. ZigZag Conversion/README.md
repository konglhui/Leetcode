# ZigZag Conversion :star::star:
- 题目地址: [https://leetcode-cn.com/problems/zigzag-conversion](https://leetcode-cn.com/problems/zigzag-conversion)
- 执行时间: 12 ms 
- 内存消耗: 8.2 MB
- 通过日期: 2020-05-22 12:45
## 题目内容
<p>将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。</p>

<p>比如输入字符串为 <code>"LEETCODEISHIRING"</code> 行数为 3 时，排列如下：</p>

<pre>L   C   I   R
E T O E S I I G
E   D   H   N
</pre>

<p>之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如：<code>"LCIRETOESIIGEDHN"</code>。</p>

<p>请你实现这个将字符串进行指定行数变换的函数：</p>

<pre>string convert(string s, int numRows);</pre>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> s = "LEETCODEISHIRING", numRows = 3
<strong>输出:</strong> "LCIRETOESIIGEDHN"
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> s = "LEETCODEISHIRING", numRows = 4
<strong>输出:</strong> "LDREOEIIECIHNTSG"
<strong>解释:</strong>

L     D     R
E   O E   I I
E C   I H   N
T     S     G</pre>

## 解法
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