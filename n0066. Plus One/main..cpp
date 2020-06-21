// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        for(;i > -1 ;i--)
        {
            digits[i] ++;
            if(digits[i] > 9)
                digits[i] = 0;
            else
                break;
        }
        if(i == -1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
