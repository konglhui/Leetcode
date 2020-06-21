// Author: klinghui @ https://github.com/konglhui/Leetcode

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


