// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size()-1; ++i)
        {
            for(int j = i+1; j <nums.size();++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    return {i,j};
                }
            }
        }
    }
};
