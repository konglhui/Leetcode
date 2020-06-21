// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:

vector<int> nums = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
vector<string> roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string intToRoman(int num) {
        string result; 
        if(num == 0)
            return result;
        auto res = num;
        for(unsigned int i =0; i < 13;i++)
        {
            const auto temp = nums[i];
            while(temp <= num)
            {
                num -= temp;
                result.append(roman[i]);
            }
        }
return result;
    }
};
