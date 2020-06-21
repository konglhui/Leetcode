# Implement Stack using Queues :star:
- 题目地址: [https://leetcode-cn.com/problems/implement-stack-using-queues](https://leetcode-cn.com/problems/implement-stack-using-queues)
- 执行时间: 0 ms 
- 内存消耗: 6.8 MB
- 通过日期: 2020-06-14 21:55
## 题目内容
<p>使用队列实现栈的下列操作：</p>

<ul>
	<li>push(x) -- 元素 x 入栈</li>
	<li>pop() -- 移除栈顶元素</li>
	<li>top() -- 获取栈顶元素</li>
	<li>empty() -- 返回栈是否为空</li>
</ul>

<p><strong>注意:</strong></p>

<ul>
	<li>你只能使用队列的基本操作-- 也就是 <code>push to back</code>, <code>peek/pop from front</code>, <code>size</code>, 和 <code>is empty</code> 这些操作是合法的。</li>
	<li>你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。</li>
	<li>你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。</li>
</ul>

## 解法
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
		
	}

	/** Push element x onto stack. */
	void push(int x) {
		_first.push(x);
		if(_first.size() != 1)
		{
			_second.push(_first.front());
			_first.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		auto resut = _first.front();
		_first.pop();
		swap(_first, _second);
		const int size = int(_first.size()) - 1;
		if(size > 0)
		{
			for(int i = 0; i < size;i++)
			{
				_second.push(_first.front());
				_first.pop();
			}
		}
		return resut;
	}

	/** Get the top element. */
	int top() {
		return _first.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return _first.empty();
	}
private:
	std::queue<int>_first;
	std::queue<int>_second;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

```