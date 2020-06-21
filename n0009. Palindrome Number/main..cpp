// Author: klinghui @ https://github.com/konglhui/Leetcode
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<10 && x>=0) 
            return true;
        if(x < 0 || x%10 == 0) 
            return false;

        int judge = 0;
        while(x > judge)
        {
            judge =judge * 10 +  x%10;
            x /= 10;
        }
        
        return judge == x || x == judge/10;
    }
};
