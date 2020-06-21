// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.empty())return 0;
		int num = 0;
        int temp = nums[0] - 1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > temp)
			{
                temp = nums[i];
				nums[num] = temp;
				num++;
			}
		}
		return num;
	}
};
