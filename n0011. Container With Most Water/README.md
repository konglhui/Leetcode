# Container With Most Water :star::star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/container-with-most-water](https://leetcode-cn.com/problems/container-with-most-water)
- ִ��ʱ��: 960 ms 
- �ڴ�����: N/A
- ͨ������: 2019-12-28 04:53
## ��Ŀ����
<p>���� <em>n</em> ���Ǹ����� <em>a</em><sub>1</sub>��<em>a</em><sub>2��</sub>...��<em>a</em><sub>n��</sub>ÿ�������������е�һ����0�2(<em>i</em>,�0�2<em>a<sub>i</sub></em>) ���������ڻ� <em>n</em> ����ֱ�ߣ���ֱ�� <em>i</em>�0�2�������˵�ֱ�Ϊ�0�2(<em>i</em>,�0�2<em>a<sub>i</sub></em>) �� (<em>i</em>, 0)���ҳ����е������ߣ�ʹ��������0�2<em>x</em>�0�2�Ṳͬ���ɵ�����������������ˮ��</p>

<p><strong>˵����</strong>�㲻����б�������ҁ0�2<em>n</em>�0�2��ֵ����Ϊ 2��</p>



<p><img alt="" src="https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg" style="height: 287px; width: 600px;"></p>

<p><small>ͼ�д�ֱ�ߴ����������� [1,8,6,2,5,4,8,3,7]���ڴ�����£������ܹ�����ˮ����ʾΪ��ɫ���֣������ֵΪ�0�249��</small></p>



<p><strong>ʾ����</strong></p>

<pre><strong>���룺</strong>[1,8,6,2,5,4,8,3,7]
<strong>�����</strong>49</pre>

## �ⷨ
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan

	inline int TwoMin(int& a,int& b)
	{
		return a > b ? b : a;
	}

class Solution {
public:
	int maxArea(std::vector<int>& height) {
        int _maxArea = 0;
        for(int i = 0; i < height.size	() - 1;i++)
		{
			for(int j =i+1;j<height.size();j++)
			{
				int temp = (j - i) * TwoMin(height[j], height[i]);
				if (_maxArea < temp)
					_maxArea = temp;
			}
		}
		return _maxArea;
	}
};



```