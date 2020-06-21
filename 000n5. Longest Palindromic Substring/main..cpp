// Author: klinghui @ https://github.com/konglhui/Leetcode
class Solution {
public:
    string longestPalindrome(string s)
    {
        if(s.size() < 2)
            return s;
        int maxi = 0,maxj = 0;
        int maxLength = 1;
        for(int i = 0,_size = s.size() ,tempi,tempj,tempLength,testnum;i < _size - 1;i++)
        {
            if(s[i] == s[i + 1])
            {
                tempi = i - 1;
                tempj = i + 2;
                test(s,tempi,tempj,maxLength,maxi,maxj);
            }
            if( i< _size - 2 && s[i] == s[i+ 2])
            {
                tempi = i - 1;
                tempj = i + 3;
                test(s,tempi,tempj,maxLength,maxi,maxj);
            }
        }
        
        return s.substr(maxi,maxLength);
    }
        
    static void test(string & s,int tempi,int tempj,int &maxLength,int & maxi,int & maxj)
    {
        while(tempi > -1 && tempj <s.size())
        {
            if(s[tempi] == s[tempj])
            {
                tempi--;
                tempj++;
            }
            else
                break;
        }
        if(maxLength <= tempj - tempi - 1)
        {
            maxLength = tempj - tempi - 1;
            maxi = tempi + 1;
            maxj = tempj - 1;
        }
    }

};

