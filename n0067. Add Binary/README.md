# Add Binary :star:
- 题目地址: [https://leetcode-cn.com/problems/add-binary](https://leetcode-cn.com/problems/add-binary)
- 执行时间: 4 ms 
- 内存消耗: N/A
- 通过日期: 2019-04-14 03:33
## 题目内容
<p>给你两个二进制字符串，返回它们的和（用二进制表示）。</p>

<p>输入为 <strong>非空 </strong>字符串且只包含数字 <code>1</code> 和 <code>0</code>。</p>



<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> a = "11", b = "1"
<strong>输出:</strong> "100"</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> a = "1010", b = "1011"
<strong>输出:</strong> "10101"</pre>



<p><strong>提示：</strong></p>

<ul>
	<li>每个字符串仅由字符 <code>'0'</code> 或 <code>'1'</code> 组成。</li>
	<li><code>1 <= a.length, b.length <= 10^4</code></li>
	<li>字符串如果不是 <code>"0"</code> ，就都不含前导零。</li>
</ul>

## 解法
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        char tmp,tmpa,tmpb;

        int i = a.size() - 1,j = b.size() - 1;
        bool andOne = false;
        while(i > -1 || j > -1 || andOne)
        {
            if( i > -1)
                tmpa = a[i];
            else
                tmpa = '0';
            if(j > -1)
                tmpb = b[j];
            else
                tmpb = '0';
            andOne = addChar(tmpa,tmpb,andOne,tmp);
            result.insert(0, 1,tmp);
            i--;
            j--;
        }
        return result;
    }
    
    
    bool addChar(char a, char b ,bool andOne, char& output)
    {
        int sum = 0;
        if(a == '1')
            sum += 1;
        if(b == '1')
            sum += 1;
        sum += andOne;
        output = (sum % 2 == 1 ? '1':'0');
        return sum/2;
    }
};

```