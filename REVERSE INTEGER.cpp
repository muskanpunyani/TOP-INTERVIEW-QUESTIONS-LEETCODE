Given a 32-bit signed integer, reverse digits of an integer.

Note:
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

 

Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

Example 4:

Input: x = 0
Output: 0

 

Constraints:

    -231 <= x <= 231 - 1


************************************
class Solution {
public:
    int reverse(int x) {
        int rev=0;
        while(x!=0)
        {
            int pop=x%10;
            x=x/10;
            if((rev> INT_MAX/10) || (rev==INT_MAX/10 && pop>7)) // for +ve overflow
                return 0;
             if((rev<INT_MIN/10) || (rev==INT_MIN/10 && pop<-8)) // for -ve overflow
                return 0;
            
            rev=rev*10+pop;
        }
        return rev;
    }
};
