// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vmap( 256,-1);
        int maxLength = 0;
        int start = -1;
        int _size = s.size();
        for(int i = 0;i < _size; i++)
        {
            if(vmap[s[i]]  != -1)
                if(start < vmap[s[i]])
                    start = vmap[s[i]];
            vmap[s[i]] = i;
            
            maxLength = max(maxLength,i - start);
        }
        return maxLength;
    }
};
