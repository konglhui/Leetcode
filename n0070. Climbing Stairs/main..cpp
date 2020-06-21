// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    int climbStairs(int n) {
        int sub = 1;
        if(n == 1)
            return sub;
        int pre = 2;
        if(n == 2)
            return pre;
        for(int i = 2;i< n;i++)
        {
            int tmp = pre;
            pre = pre + sub;
            sub = tmp;
        }
        return pre;
    }
};
