# Roman to Integer :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/roman-to-integer](https://leetcode-cn.com/problems/roman-to-integer)
- ִ��ʱ��: 68 ms 
- �ڴ�����: N/A
- ͨ������: 2018-09-26 23:50
## ��Ŀ����
<p>�������ְ������������ַ�:�0�2<code>I</code>���0�2<code>V</code>���0�2<code>X</code>���0�2<code>L</code>��<code>C</code>��<code>D</code>�0�2�́0�2<code>M</code>��</p>

<pre><strong>�ַ�</strong>          <strong>��ֵ</strong>
I             1
V             5
X             10
L             50
C             100
D             500
M             1000</pre>

<p>���磬 �������� 2 д���0�2<code>II</code>�0�2����Ϊ�������е� 1��12 д���0�2<code>XII</code>�0�2����Ϊ�0�2<code>X</code>�0�2+�0�2<code>II</code>�0�2�� 27 д���0�2�0�2<code>XXVII</code>, ��Ϊ�0�2<code>XX</code>�0�2+�0�2<code>V</code>�0�2+�0�2<code>II</code>�0�2��</p>

<p>ͨ������£�����������С�������ڴ�����ֵ��ұߡ���Ҳ�������������� 4 ��д���0�2<code>IIII</code>�����ǁ0�2<code>IV</code>������ 1 ������ 5 ����ߣ�����ʾ�������ڴ��� 5 ��С�� 1 �õ�����ֵ 4 ��ͬ���أ����� 9 ��ʾΪ�0�2<code>IX</code>���������Ĺ���ֻ�������������������</p>

<ul>
	<li><code>I</code>�0�2���Է��ځ0�2<code>V</code>�0�2(5) �́0�2<code>X</code>�0�2(10) ����ߣ�����ʾ 4 �� 9��</li>
	<li><code>X</code>�0�2���Է��ځ0�2<code>L</code>�0�2(50) �́0�2<code>C</code>�0�2(100) ����ߣ�����ʾ 40 �́0�290���0�2</li>
	<li><code>C</code>�0�2���Է��ځ0�2<code>D</code>�0�2(500) �́0�2<code>M</code>�0�2(1000) ����ߣ�����ʾ�0�2400 �́0�2900��</li>
</ul>

<p>����һ���������֣�����ת��������������ȷ���� 1�0�2�� 3999 �ķ�Χ�ڡ�</p>

<p><strong>ʾ���0�21:</strong></p>

<pre><strong>����:</strong>�0�2"III"
<strong>���:</strong> 3</pre>

<p><strong>ʾ���0�22:</strong></p>

<pre><strong>����:</strong>�0�2"IV"
<strong>���:</strong> 4</pre>

<p><strong>ʾ���0�23:</strong></p>

<pre><strong>����:</strong>�0�2"IX"
<strong>���:</strong> 9</pre>

<p><strong>ʾ���0�24:</strong></p>

<pre><strong>����:</strong>�0�2"LVIII"
<strong>���:</strong> 58
<strong>����:</strong> L = 50, V= 5, III = 3.
</pre>

<p><strong>ʾ���0�25:</strong></p>

<pre><strong>����:</strong>�0�2"MCMXCIV"
<strong>���:</strong> 1994
<strong>����:</strong> M = 1000, CM = 900, XC = 90, IV = 4.</pre>

## �ⷨ
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