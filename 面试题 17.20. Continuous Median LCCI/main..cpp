// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		if(_greater.empty())
		{
			_greater.push(num);
			return;
		}
		if (num < _greater.top())
			_greater.push(num);
		else
			_less.push(num);
		
		if (_less.size() == _greater.size() || _greater.size() - _less.size() == 1)
			return;
		
		if(_less.size()>_greater.size())
		{
			_greater.push(_less.top());
			_less.pop();
		}
		if(_greater.size() - _less.size() == 2)
		{
			_less.push(_greater.top());
			_greater.pop();
		}
	}

	double findMedian() {
		if (_less.size() == _greater.size())
			return double(_less.top() + _greater.top()) / 2;
		else
			return _greater.top();
	}
	std::priority_queue<int, vector<int>, less<int>> _greater{};
	std::priority_queue<int,vector<int>,greater<int>> _less{};
};
