// Author: klinghui @ https://github.com/konglhui/Leetcode
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
