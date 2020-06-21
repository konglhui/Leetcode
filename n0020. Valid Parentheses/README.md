# Valid Parentheses :star:
- 题目地址: [https://leetcode-cn.com/problems/valid-parentheses](https://leetcode-cn.com/problems/valid-parentheses)
- 执行时间: 4 ms 
- 内存消耗: 6.5 MB
- 通过日期: 2020-06-14 21:13
## 题目内容
<p>给定一个只包括 <code>'('</code>，<code>')'</code>，<code>'{'</code>，<code>'}'</code>，<code>'['</code>，<code>']'</code> 的字符串，判断字符串是否有效。</p>

<p>有效字符串需满足：</p>

<ol>
	<li>左括号必须用相同类型的右括号闭合。</li>
	<li>左括号必须以正确的顺序闭合。</li>
</ol>

<p>注意空字符串可被认为是有效字符串。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> "()"
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> "()[]{}"
<strong>输出:</strong> true
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> "(]"
<strong>输出:</strong> false
</pre>

<p><strong>示例 4:</strong></p>

<pre><strong>输入:</strong> "([)]"
<strong>输出:</strong> false
</pre>

<p><strong>示例 5:</strong></p>

<pre><strong>输入:</strong> "{[]}"
<strong>输出:</strong> true</pre>

## 解法
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
	const std::unordered_map<char,char> maps = { {'(',')'},{'{', '}'},{'[' , ']' } };
	bool isValid(string s) {

		stack<char> temp;
		for(const auto& ss:s)
		{
			auto temp_map = maps.find(ss);
			if (temp_map != maps.end())
			{
				temp.push(temp_map->second);
				continue;
			}
			if (temp.empty() || !(temp.top() == ss))
				return false;
			temp.pop();
		}
        if(temp.empty())
		    return true;
        return false;
	}
};

```