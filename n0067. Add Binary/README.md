# Add Binary :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/add-binary](https://leetcode-cn.com/problems/add-binary)
- ִ��ʱ��: 4 ms 
- �ڴ�����: N/A
- ͨ������: 2019-04-14 03:33
## ��Ŀ����
<p>���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����</p>

<p>����Ϊ <strong>�ǿ� </strong>�ַ�����ֻ�������ց0�2<code>1</code>�0�2�́0�2<code>0</code>��</p>



<p><strong>ʾ���0�21:</strong></p>

<pre><strong>����:</strong> a = "11", b = "1"
<strong>���:</strong> "100"</pre>

<p><strong>ʾ���0�22:</strong></p>

<pre><strong>����:</strong> a = "1010", b = "1011"
<strong>���:</strong> "10101"</pre>



<p><strong>��ʾ��</strong></p>

<ul>
	<li>ÿ���ַ��������ַ� <code>'0'</code> �� <code>'1'</code> ��ɡ�</li>
	<li><code>1 <= a.length, b.length <= 10^4</code></li>
	<li>�ַ���������� <code>"0"</code> ���Ͷ�����ǰ���㡣</li>
</ul>

## �ⷨ
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