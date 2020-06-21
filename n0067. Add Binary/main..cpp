// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        char tmp,tmpa,tmpb;

        int i = a.size() - 1,j = b.size() - 1;
        bool andOne = false;
        while(i > -1 || j > -1 || andOne)
        {
            if( i > -1)
                tmpa = a[i];
            else
                tmpa = '0';
            if(j > -1)
                tmpb = b[j];
            else
                tmpb = '0';
            andOne = addChar(tmpa,tmpb,andOne,tmp);
            result.insert(0, 1,tmp);
            i--;
            j--;
        }
        return result;
    }
    
    
    bool addChar(char a, char b ,bool andOne, char& output)
    {
        int sum = 0;
        if(a == '1')
            sum += 1;
        if(b == '1')
            sum += 1;
        sum += andOne;
        output = (sum % 2 == 1 ? '1':'0');
        return sum/2;
    }
};
