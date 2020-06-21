# Implement Queue using Stacks :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/implement-queue-using-stacks](https://leetcode-cn.com/problems/implement-queue-using-stacks)
- ִ��ʱ��: 0 ms 
- �ڴ�����: 6.9 MB
- ͨ������: 2020-06-14 22:08
## ��Ŀ����
<p>ʹ��ջʵ�ֶ��е����в�����</p>

<ul>
	<li>push(x) -- ��һ��Ԫ�ط�����е�β����</li>
	<li>pop() -- �Ӷ����ײ��Ƴ�Ԫ�ء�</li>
	<li>peek() -- ���ض����ײ���Ԫ�ء�</li>
	<li>empty() -- ���ض����Ƿ�Ϊ�ա�</li>
</ul>



<p><strong>ʾ��:</strong></p>

<pre>MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // ���� 1
queue.pop();   // ���� 1
queue.empty(); // ���� false</pre>



<p><strong>˵��:</strong></p>

<ul>
	<li>��ֻ��ʹ�ñ�׼��ջ���� -- Ҳ����ֻ�Ё0�2<code>push to top</code>,�0�2<code>peek/pop from top</code>,�0�2<code>size</code>, �́0�2<code>is empty</code>�0�2�����ǺϷ��ġ�</li>
	<li>����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�</li>
	<li>�������в���������Ч�� �����磬һ���յĶ��в������ pop ���� peek ��������</li>
</ul>

## �ⷨ
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		_first.push(x);
		if(_second.empty())
		{
			firstToSecond();
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		auto result  = _second.top();
        _second.pop();
		if (_second.empty())
			firstToSecond();
        return result;
	}

	/** Get the front element. */
	int peek() {
		return _second.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return _second.empty();
	}
private:
	void firstToSecond()
	{
		while (!_first.empty())
		{
			_second.push(_first.top());
			_first.pop();
		}
	}
private:
	std::stack<int> _first;
	std::stack<int> _second;
	
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

```