// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN,tmp = 0;
        for(int i : nums)
        {
            tmp += i;
            if(result < tmp)
                result = tmp;
            if(tmp < 0)
                tmp = 0;
        }
        return result;
    }

};
