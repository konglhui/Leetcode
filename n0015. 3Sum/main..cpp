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
