// Author: klinghui @ https://github.com/konglhui/Leetcode
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;

        for(int i = 0, _size = haystack.size(); i< _size;i++)
        {
            if(haystack[i] == needle[0])
                if(judgeStr(haystack,needle,i))
                    return i;
        }
        return -1;

    }
    
    bool judgeStr(string &stack,string &needle,int inputI)
    {
        if(stack.size() - inputI < needle.size())
            return false;
        
        for(int i = 1,_size = needle.size();i < _size;i++)
        {
            if(stack[inputI + i] != needle[i])
                return false;
        }
        return true;
    }
};
