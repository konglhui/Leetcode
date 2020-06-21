# 3Sum :star::star:
- 题目地址: [https://leetcode-cn.com/problems/3sum](https://leetcode-cn.com/problems/3sum)
- 执行时间: 68 ms 
- 内存消耗: 19.6 MB
- 通过日期: 2020-05-25 01:04
## 题目内容
<p>给你一个包含 <em>n</em> 个整数的数组 <code>nums</code>，判断 <code>nums</code> 中是否存在三个元素 <em>a，b，c ，</em>使得 <em>a + b + c = </em>0 ？请你找出所有满足条件且不重复的三元组。</p>

<p><strong>注意：</strong>答案中不可以包含重复的三元组。</p>



<p><strong>示例：</strong></p>

<pre>给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
</pre>

## 解法
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > result;
	
	for (std::size_t i = 0, size = nums.size(); i < size; i++)
	{
		const int target = -nums[i];
		if(target < 0)
			break;
		std::size_t front = i+1, back = size - 1;
		while (front < back)
		{
			int temp = nums[front] + nums[back];
			if (temp < target)
				front++;
			else if (temp > target)
				back--;
			else
			{
				const auto front_value = nums[front];
				//const auto value = nums[i];
				const auto back_value = nums[back];
				result.push_back(vector<int>{front_value,  nums[i], back_value});
				while (front < back && nums[front] == front_value) front++;
				while (front < back && nums[back] == back_value) back--;
			}
		}
		while (i + 1 < size && nums[i + 1] == nums[i]) i++;
	}
	return  result;
    }
};

```