# Length of Last Word :star:
- 题目地址: [https://leetcode-cn.com/problems/length-of-last-word](https://leetcode-cn.com/problems/length-of-last-word)
- 执行时间: 4 ms 
- 内存消耗: N/A
- 通过日期: 2019-04-13 01:04
## 题目内容
<p>给定一个仅包含大小写字母和空格 <code>' '</code> 的字符串 <code>s</code>，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。</p>

<p>如果不存在最后一个单词，请返回 0 。</p>

<p><strong>说明：</strong>一个单词是指仅由字母组成、不包含任何空格字符的 <strong>最大子字符串</strong>。</p>



<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> "Hello World"
<strong>输出:</strong> 5
</pre>

## 解法
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    int lengthOfLastWord(string s) {
        int _size = s.size();
        int result = 0;
        for(int i = _size - 1; i > -1;--i)
        {
            if(result == 0 && s[i] == ' ')
                continue;
            if(s[i] == ' ')
                break;
            result++;
        }
        return result;
    }
};

```