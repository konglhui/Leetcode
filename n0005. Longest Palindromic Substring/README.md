# Longest Palindromic Substring :star::star:
- 题目地址: [https://leetcode-cn.com/problems/longest-palindromic-substring](https://leetcode-cn.com/problems/longest-palindromic-substring)
- 执行时间: 16 ms 
- 内存消耗: N/A
- 通过日期: 2019-04-22 00:10
## 题目内容
<p>给定一个字符串 <code>s</code>，找到 <code>s</code> 中最长的回文子串。你可以假设 <code>s</code> 的最大长度为 1000。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> "babad"
<strong>输出:</strong> "bab"
<strong>注意:</strong> "aba" 也是一个有效答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> "cbbd"
<strong>输出:</strong> "bb"
</pre>

## 解法
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