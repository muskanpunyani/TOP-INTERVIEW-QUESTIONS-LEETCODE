Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

    Starting with any positive integer, replace the number by the sum of the squares of its digits.
    Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    Those numbers for which this process ends in 1 are happy.

Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:

Input: n = 2
Output: false

 

Constraints:

    1 <= n <= 231 - 1


***************
class Solution {
public:
    bool isHappy(int n) {
        if(n==1 || n==7)    
            return true;
        int x=n;
        while(x>9)     // till no reduces to single digit
        {
            int sum=0;
            while(x>0){    // finding square
            int r=x%10;
            sum+=(r*r);
            x=x/10;
            }
            if(sum==1 || sum==7)  // if 1 or 7 happy no
                return true;
            x=sum;
            
        }
        return false;
    }
};
