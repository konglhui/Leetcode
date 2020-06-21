# Continuous Median LCCI :star::star::star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/continuous-median-lcci](https://leetcode-cn.com/problems/continuous-median-lcci)
- ִ��ʱ��: 252 ms 
- �ڴ�����: 41.9 MB
- ͨ������: 2020-06-20 00:24
## ��Ŀ����
<p>����������ֲ����ݸ�һ�����������ܷ���������������ÿ�β�����ֵʱ��Ѱ�ҵ�ǰ����ֵ���м�ֵ����λ���������档</p>

<p>��λ���������б��м����������б�����ż������λ�������м���������ƽ��ֵ��</p>

<p>���磬</p>

<p>[2,3,4]�0�2����λ���� 3</p>

<p>[2,3] ����λ���� (2 + 3) / 2 = 2.5</p>

<p>���һ��֧���������ֲ��������ݽṹ��</p>

<ul>
	<li>void addNum(int num) - �������������һ�����������ݽṹ�С�</li>
	<li>double findMedian() - ����Ŀǰ����Ԫ�ص���λ����</li>
</ul>

<p><strong>ʾ����</strong></p>

<pre>addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
</pre>

## �ⷨ
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