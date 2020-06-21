// Author: klinghui @ https://github.com/konglhui/Leetcode
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
