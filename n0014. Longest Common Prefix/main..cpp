// Author: klinghui @ https://github.com/konglhui/Leetcode
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];

        int size = strs.size();
        string result = "";
        int m = 0;
        while(true)
        {
            char a = strs[0][m];
            int n = 1;
            for(int i = 1;i < size;i++)
            {
                if(strs[i].size() > m && strs[i][m] == a)
                    n++;
            }
            
            if(n == size)
            {
                result += strs[0][m];
                m++;
            }
                
            else
                break;
        } 
        return result;  
        
    }
};
