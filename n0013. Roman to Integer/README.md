# Roman to Integer :star:
- 题目地址: [https://leetcode-cn.com/problems/roman-to-integer](https://leetcode-cn.com/problems/roman-to-integer)
- 执行时间: 68 ms 
- 内存消耗: N/A
- 通过日期: 2018-09-26 23:50
## 题目内容
<p>罗马数字包含以下七种字符: <code>I</code>， <code>V</code>， <code>X</code>， <code>L</code>，<code>C</code>，<code>D</code> 和 <code>M</code>。</p>

<pre><strong>字符</strong>          <strong>数值</strong>
I             1
V             5
X             10
L             50
C             100
D             500
M             1000</pre>

<p>例如， 罗马数字 2 写做 <code>II</code> ，即为两个并列的 1。12 写做 <code>XII</code> ，即为 <code>X</code> + <code>II</code> 。 27 写做  <code>XXVII</code>, 即为 <code>XX</code> + <code>V</code> + <code>II</code> 。</p>

<p>通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 <code>IIII</code>，而是 <code>IV</code>。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 <code>IX</code>。这个特殊的规则只适用于以下六种情况：</p>

<ul>
	<li><code>I</code> 可以放在 <code>V</code> (5) 和 <code>X</code> (10) 的左边，来表示 4 和 9。</li>
	<li><code>X</code> 可以放在 <code>L</code> (50) 和 <code>C</code> (100) 的左边，来表示 40 和 90。 </li>
	<li><code>C</code> 可以放在 <code>D</code> (500) 和 <code>M</code> (1000) 的左边，来表示 400 和 900。</li>
</ul>

<p>给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> "III"
<strong>输出:</strong> 3</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> "IV"
<strong>输出:</strong> 4</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> "IX"
<strong>输出:</strong> 9</pre>

<p><strong>示例 4:</strong></p>

<pre><strong>输入:</strong> "LVIII"
<strong>输出:</strong> 58
<strong>解释:</strong> L = 50, V= 5, III = 3.
</pre>

<p><strong>示例 5:</strong></p>

<pre><strong>输入:</strong> "MCMXCIV"
<strong>输出:</strong> 1994
<strong>解释:</strong> M = 1000, CM = 900, XC = 90, IV = 4.</pre>

## 解法
```cpp
// Author: klinghui @ https://github.com/konglhui/Leetcode
class Solution {
public:
    int romanToInt(string s) 
    {
        int number = 0;
        std::map<char,int> sMap;
        sMap['I'] = 1;
        sMap['V'] = 5;
        sMap['X'] = 10;
        sMap['L'] = 50;
        sMap['C'] = 100;
        sMap['D'] = 500;
        sMap['M'] = 1000;
        number += sMap[s[s.size()-1]];
        for (int i = s.size()-2;i>=0;--i)
        {

            if(sMap[s[i]]<sMap[s[i+1]])
            {
                number -= sMap[s[i]];
            }
            else
            {
                number += sMap[s[i]];    
            }
        }
        
        return number;
    }   
};

```