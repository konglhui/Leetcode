# Longest Common Prefix :star:
- 题目地址: [https://leetcode-cn.com/problems/longest-common-prefix](https://leetcode-cn.com/problems/longest-common-prefix)
- 执行时间: 8 ms 
- 内存消耗: N/A
- 通过日期: 2019-03-27 23:59
## 题目内容
<p>编写一个函数来查找字符串数组中的最长公共前缀。</p>

<p>如果不存在公共前缀，返回空字符串 <code>""</code>。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>["flower","flow","flight"]
<strong>输出:</strong> "fl"
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>["dog","racecar","car"]
<strong>输出:</strong> ""
<strong>解释:</strong> 输入不存在公共前缀。
</pre>

<p><strong>说明:</strong></p>

<p>所有输入只包含小写字母 <code>a-z</code> 。</p>

## 解法
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