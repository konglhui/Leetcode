// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0 ,_size = nums.size();i<_size;i++)
        {
            if(target <= nums[i])
                    return i;
 
        }
        return nums.size();
    }
};
