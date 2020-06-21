# Longest Substring Without Repeating Characters :star::star:
- 题目地址: [https://leetcode-cn.com/problems/longest-substring-without-repeating-characters](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters)
- 执行时间: 20 ms 
- 内存消耗: N/A
- 通过日期: 2019-04-21 15:50
## 题目内容
<p>给定一个字符串，请你找出其中不含有重复字符的 <strong>最长子串 </strong>的长度。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>"abcabcbb"
<strong>输出: </strong>3 
<strong>解释:</strong> 因为无重复字符的最长子串是 <code>"abc"，所以其</code>长度为 3。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>"bbbbb"
<strong>输出: </strong>1
<strong>解释: </strong>因为无重复字符的最长子串是 <code>"b"</code>，所以其长度为 1。
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入: </strong>"pwwkew"
<strong>输出: </strong>3
<strong>解释: </strong>因为无重复字符的最长子串是 <code>"wke"</code>，所以其长度为 3。
     请注意，你的答案必须是 <strong>子串 </strong>的长度，<code>"pwke"</code> 是一个<em>子序列，</em>不是子串。
</pre>

## 解法
```cpp
// Author: klinghui @ https://github.com/konglhui/Leetcode
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vmap( 256,-1);
        int maxLength = 0;
        int start = -1;
        int _size = s.size();
        for(int i = 0;i < _size; i++)
        {
            if(vmap[s[i]]  != -1)
                if(start < vmap[s[i]])
                    start = vmap[s[i]];
            vmap[s[i]] = i;
            
            maxLength = max(maxLength,i - start);
        }
        return maxLength;
    }
};

```