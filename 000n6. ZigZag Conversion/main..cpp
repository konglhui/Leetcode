// Author: klinghui @ https://github.com/konglhui/Leetcode
class Solution {
public:
    string convert(string s, int numRows) 
    {
        if(numRows == 1)
            return s;
        string result;
        const unsigned int size = s.size();
        const unsigned int half_length = numRows -1;
        const unsigned int ont_length = half_length * 2;
        const unsigned int time = size / ont_length + 1;
        for(unsigned int i = 0; i < numRows;i++)
        {
            for(unsigned int j = 0; j < time;j++)
            {
                const unsigned int start = ont_length *j;
                const unsigned int first = start + i;

                if(size <= first)
                    continue;
                result.push_back(s[first]);

                if(i != 0 && i != numRows - 1)
                {
                    unsigned int second = start + ont_length - i ;
                    if(size > second)
                        result.push_back(s[second]);
                }
            }
        }
        return result;
    }
};
