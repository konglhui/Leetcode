// Author: klinghui @ https://github.com/konglhui/Leetcode
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
