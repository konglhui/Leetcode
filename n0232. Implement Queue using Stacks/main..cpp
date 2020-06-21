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
