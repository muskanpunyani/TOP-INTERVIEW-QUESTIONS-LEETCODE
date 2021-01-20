Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

 

Constraints:

    1 <= n <= 104


****************************************
class Solution {
public:
    /*
    Space : O(n)
    Time : O(n*sqrt(n))
    */
    int result(int n,int dp[100000])
    {
      if(floor(sqrt(n))==ceil(sqrt(n))) // PERFECT SQUARE
      {
          return 1;
      }
        if(n<=3)                       
        {
            return n;
        }
        if(dp[n]!=-1)   // IF ALREADY EXIS THEN RETURN VAL
        {
            return dp[n];
        }
        int ans=n;
        for(int i=1;i<=n;i++)
        {
            int temp=i*i;
            if(temp>n)
            {
                break;
            }
            else{
                ans= min(1+result(n-temp,dp),ans); //WE WILL TAKE THAT SQUARE AND RECURSE
            }
        }
        dp[n]=ans;
        return dp[n];
    }
    int numSquares(int n) {
        int dp[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=-1;
        }
        int ans=result(n,dp);
        return ans;
        
    }
};
