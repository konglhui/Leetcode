# Integer to Roman :star::star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/integer-to-roman](https://leetcode-cn.com/problems/integer-to-roman)
- ִ��ʱ��: 20 ms 
- �ڴ�����: 8.9 MB
- ͨ������: 2020-05-23 13:20
## ��Ŀ����
<p>�������ְ������������ַ����0�2<code>I</code>���0�2<code>V</code>���0�2<code>X</code>���0�2<code>L</code>��<code>C</code>��<code>D</code>�0�2�́0�2<code>M</code>��</p>

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

<p>����һ������������תΪ�������֡�����ȷ���� 1�0�2�� 3999 �ķ�Χ�ڡ�</p>

<p><strong>ʾ���0�21:</strong></p>

<pre><strong>����:</strong>�0�23
<strong>���:</strong> "III"</pre>

<p><strong>ʾ���0�22:</strong></p>

<pre><strong>����:</strong>�0�24
<strong>���:</strong> "IV"</pre>

<p><strong>ʾ���0�23:</strong></p>

<pre><strong>����:</strong>�0�29
<strong>���:</strong> "IX"</pre>

<p><strong>ʾ���0�24:</strong></p>

<pre><strong>����:</strong>�0�258
<strong>���:</strong> "LVIII"
<strong>����:</strong> L = 50, V = 5, III = 3.
</pre>

<p><strong>ʾ���0�25:</strong></p>

<pre><strong>����:</strong>�0�21994
<strong>���:</strong> "MCMXCIV"
<strong>����:</strong> M = 1000, CM = 900, XC = 90, IV = 4.</pre>

## �ⷨ
```cpp
// Author: klinghui @ https://github.com/konglhui/Leetcode
class Solution {
public:

vector<int> nums = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
vector<string> roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string intToRoman(int num) {
        string result; 
        if(num == 0)
            return result;
        auto res = num;
        for(unsigned int i =0; i < 13;i++)
        {
            const auto temp = nums[i];
            while(temp <= num)
            {
                num -= temp;
                result.append(roman[i]);
            }
        }
return result;
    }
};

```