// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    int romanToInt(string s) 
    {
        int number = 0;
        std::map<char,int> sMap;
        sMap['I'] = 1;
        sMap['V'] = 5;
        sMap['X'] = 10;
        sMap['L'] = 50;
        sMap['C'] = 100;
        sMap['D'] = 500;
        sMap['M'] = 1000;
        number += sMap[s[s.size()-1]];
        for (int i = s.size()-2;i>=0;--i)
        {

            if(sMap[s[i]]<sMap[s[i+1]])
            {
                number -= sMap[s[i]];
            }
            else
            {
                number += sMap[s[i]];    
            }
        }
        
        return number;
    }   
};
