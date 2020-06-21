// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    int lengthOfLastWord(string s) {
        int _size = s.size();
        int result = 0;
        for(int i = _size - 1; i > -1;--i)
        {
            if(result == 0 && s[i] == ' ')
                continue;
            if(s[i] == ' ')
                break;
            result++;
        }
        return result;
    }
};
