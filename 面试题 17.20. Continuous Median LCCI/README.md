# Continuous Median LCCI :star::star::star:
- 题目地址: [https://leetcode-cn.com/problems/continuous-median-lcci](https://leetcode-cn.com/problems/continuous-median-lcci)
- 执行时间: 252 ms 
- 内存消耗: 41.9 MB
- 通过日期: 2020-06-20 00:24
## 题目内容
<p>随机产生数字并传递给一个方法。你能否完成这个方法，在每次产生新值时，寻找当前所有值的中间值（中位数）并保存。</p>

<p>中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。</p>

<p>例如，</p>

<p>[2,3,4] 的中位数是 3</p>

<p>[2,3] 的中位数是 (2 + 3) / 2 = 2.5</p>

<p>设计一个支持以下两种操作的数据结构：</p>

<ul>
	<li>void addNum(int num) - 从数据流中添加一个整数到数据结构中。</li>
	<li>double findMedian() - 返回目前所有元素的中位数。</li>
</ul>

<p><strong>示例：</strong></p>

<pre>addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
</pre>

## 解法
```cpp
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

```