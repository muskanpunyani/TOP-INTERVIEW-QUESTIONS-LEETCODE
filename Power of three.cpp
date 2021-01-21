Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

 

Example 1:

Input: n = 27
Output: true

Example 2:

Input: n = 0
Output: false

Example 3:

Input: n = 9
Output: true

Example 4:

Input: n = 45
Output: false

 

Constraints:

    -231 <= n <= 231 - 1

 
Follow up: Could you do it without using any loop / recursion?
***********************
class Solution {
public:
    /*
    n=3^x
    logn=xlog3
    x=logn/log3 (base 10)
    */
    bool isPowerOfThree(int n) {
        if(n==0)
            return false;
        if(n==1)
            return true;
        double a1=log10(n);
        double a2=log10(3);
        double val=double(a1/a2);
        return  floor(val)==ceil(val); // if floorand ceil are same,true else false
    }
};
