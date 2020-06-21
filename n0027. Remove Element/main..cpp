// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int size = nums.size();
        int times = 0;
        int i = 0;
        int ____size = size - 1 ;
        while(i + times < size)
        {
            if(nums[____size - times] == val)
            {
                times++;
                continue;
            }
            if(nums[i] == val)
            {
                swapNums(nums[____size - times],nums[i]);
                times++;
                continue;
            }
            i++;
        }
        return size - times;
    }
    
    void swapNums(int & a,int & b)
    {
        int c = a;
        a = b;
        b = c;
    }

};
