Given an integer n, return the number of trailing zeroes in n!.

Follow up: Could you write a solution that works in logarithmic time complexity?

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.

Example 3:

Input: n = 0
Output: 0

 

Constraints:

    0 <= n <= 104


************************
class Solution {
public:
    int trailingZeroes(int n) {
        /*1!=1
        2!=2
        3!=6
        4!=24
        5!=120
        6!=720
        10!= 3628800
        15!=1307674368000
        20!=2432902008176640000
     we can see the pattern, at 5,one 0 is added
     at 10,15,20....0s are added
     but.....
     25!== 6 trailing 0s, here 2 zeros are increased,wwhy so?25=5*5
      Well, what numbers will contribute more than one 5? Ok, you may notice that only multiples of the power of 5 will contribute more than one 5. For example, multiples of 25 will contribute at least two 5's.

Well, how to count them all? If you try some examples, you may finally get the result, which is n / 5 + n / 25 + n / 125 + .... The idea behind this expression is: all the multiples of 5 will contribute one 5, the multiples of 25 will contribute one more 5 and the multiples of 125 will contribute another one more 5... and so on.
     */
        //log5(n)=time

        int ans=0;
        for(int i=5;n/i>0;i=i*5) // loop till n/i is greater than 0 0
        {
            ans+=(n/i);
        }
        return ans;
    }
    /*
    eg. 30
    ans=0
    ans=(n/5)= (30/5)=6
    now i=25, n/i>0
    ans+=(n/i)=6+(30/25)=6+1=7
    now i=125 ,n/i is not greater than o stop.
    
    */
};
