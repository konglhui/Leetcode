# Implement Stack using Queues :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/implement-stack-using-queues](https://leetcode-cn.com/problems/implement-stack-using-queues)
- ִ��ʱ��: 0 ms 
- �ڴ�����: 6.8 MB
- ͨ������: 2020-06-14 21:55
## ��Ŀ����
<p>ʹ�ö���ʵ��ջ�����в�����</p>

<ul>
	<li>push(x) -- Ԫ�� x ��ջ</li>
	<li>pop() -- �Ƴ�ջ��Ԫ��</li>
	<li>top() -- ��ȡջ��Ԫ��</li>
	<li>empty() -- ����ջ�Ƿ�Ϊ��</li>
</ul>

<p><strong>ע��:</strong></p>

<ul>
	<li>��ֻ��ʹ�ö��еĻ�������-- Ҳ���ǁ0�2<code>push to back</code>, <code>peek/pop from front</code>, <code>size</code>, �́0�2<code>is empty</code>�0�2��Щ�����ǺϷ��ġ�</li>
	<li>����ʹ�õ�����Ҳ��֧�ֶ��С��0�2�����ʹ�� list ���� deque��˫�˶��У���ģ��һ�����Ё0�2, ֻҪ�Ǳ�׼�Ķ��в������ɡ�</li>
	<li>����Լ������в���������Ч�ģ�����, ��һ���յ�ջ������� pop ���� top ��������</li>
</ul>

## �ⷨ
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