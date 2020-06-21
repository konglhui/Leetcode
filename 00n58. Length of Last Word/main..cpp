// Author: klinghui @ https://github.com/konglhui/Leetcode
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
