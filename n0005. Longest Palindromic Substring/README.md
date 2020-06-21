# Longest Palindromic Substring :star::star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/longest-palindromic-substring](https://leetcode-cn.com/problems/longest-palindromic-substring)
- ִ��ʱ��: 16 ms 
- �ڴ�����: N/A
- ͨ������: 2019-04-22 00:10
## ��Ŀ����
<p>����һ���ַ��� <code>s</code>���ҵ� <code>s</code> ����Ļ����Ӵ�������Լ���0�2<code>s</code> ����󳤶�Ϊ 1000��</p>

<p><strong>ʾ�� 1��</strong></p>

<pre><strong>����:</strong> "babad"
<strong>���:</strong> "bab"
<strong>ע��:</strong> "aba" Ҳ��һ����Ч�𰸡�
</pre>

<p><strong>ʾ�� 2��</strong></p>

<pre><strong>����:</strong> "cbbd"
<strong>���:</strong> "bb"
</pre>

## �ⷨ
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    string longestPalindrome(string s)
    {
        if(s.size() < 2)
            return s;
        int maxi = 0,maxj = 0;
        int maxLength = 1;
        for(int i = 0,_size = s.size() ,tempi,tempj,tempLength,testnum;i < _size - 1;i++)
        {
            if(s[i] == s[i + 1])
            {
                tempi = i - 1;
                tempj = i + 2;
                test(s,tempi,tempj,maxLength,maxi,maxj);
            }
            if( i< _size - 2 && s[i] == s[i+ 2])
            {
                tempi = i - 1;
                tempj = i + 3;
                test(s,tempi,tempj,maxLength,maxi,maxj);
            }
        }
        
        return s.substr(maxi,maxLength);
    }
        
    static void test(string & s,int tempi,int tempj,int &maxLength,int & maxi,int & maxj)
    {
        while(tempi > -1 && tempj <s.size())
        {
            if(s[tempi] == s[tempj])
            {
                tempi--;
                tempj++;
            }
            else
                break;
        }
        if(maxLength <= tempj - tempi - 1)
        {
            maxLength = tempj - tempi - 1;
            maxi = tempi + 1;
            maxj = tempj - 1;
        }
    }

};


```