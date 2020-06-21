# Longest Common Prefix :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/longest-common-prefix](https://leetcode-cn.com/problems/longest-common-prefix)
- ִ��ʱ��: 8 ms 
- �ڴ�����: N/A
- ͨ������: 2019-03-27 23:59
## ��Ŀ����
<p>��дһ�������������ַ��������е������ǰ׺��</p>

<p>��������ڹ���ǰ׺�����ؿ��ַ����0�2<code>""</code>��</p>

<p><strong>ʾ���0�21:</strong></p>

<pre><strong>����: </strong>["flower","flow","flight"]
<strong>���:</strong> "fl"
</pre>

<p><strong>ʾ���0�22:</strong></p>

<pre><strong>����: </strong>["dog","racecar","car"]
<strong>���:</strong> ""
<strong>����:</strong> ���벻���ڹ���ǰ׺��
</pre>

<p><strong>˵��:</strong></p>

<p>��������ֻ����Сд��ĸ�0�2<code>a-z</code>�0�2��</p>

## �ⷨ
```cpp
// Author: klinghui @ https://github.com/konglhui/Leetcode
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];

        int size = strs.size();
        string result = "";
        int m = 0;
        while(true)
        {
            char a = strs[0][m];
            int n = 1;
            for(int i = 1;i < size;i++)
            {
                if(strs[i].size() > m && strs[i][m] == a)
                    n++;
            }
            
            if(n == size)
            {
                result += strs[0][m];
                m++;
            }
                
            else
                break;
        } 
        return result;  
        
    }
};

```