# Valid Parentheses :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/valid-parentheses](https://leetcode-cn.com/problems/valid-parentheses)
- ִ��ʱ��: 4 ms 
- �ڴ�����: 6.5 MB
- ͨ������: 2020-06-14 21:13
## ��Ŀ����
<p>����һ��ֻ���� <code>'('</code>��<code>')'</code>��<code>'{'</code>��<code>'}'</code>��<code>'['</code>��<code>']'</code>�0�2���ַ������ж��ַ����Ƿ���Ч��</p>

<p>��Ч�ַ��������㣺</p>

<ol>
	<li>�����ű�������ͬ���͵������űպϡ�</li>
	<li>�����ű�������ȷ��˳��պϡ�</li>
</ol>

<p>ע����ַ����ɱ���Ϊ����Ч�ַ�����</p>

<p><strong>ʾ�� 1:</strong></p>

<pre><strong>����:</strong> "()"
<strong>���:</strong> true
</pre>

<p><strong>ʾ���0�22:</strong></p>

<pre><strong>����:</strong> "()[]{}"
<strong>���:</strong> true
</pre>

<p><strong>ʾ���0�23:</strong></p>

<pre><strong>����:</strong> "(]"
<strong>���:</strong> false
</pre>

<p><strong>ʾ���0�24:</strong></p>

<pre><strong>����:</strong> "([)]"
<strong>���:</strong> false
</pre>

<p><strong>ʾ���0�25:</strong></p>

<pre><strong>����:</strong> "{[]}"
<strong>���:</strong> true</pre>

## �ⷨ
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