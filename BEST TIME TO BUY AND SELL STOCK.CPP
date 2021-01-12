1] BEST TIME TO BUY AND SELL STOCK 1
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.

Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.



class Solution {
public:
    int answer(vector<int>& prices,int flag,int i,int c,int dp[][3])
    {
        int l=prices.size();
        if(i>=l || c==1)
        {
            return 0;
        }
        int res=0;
        if(dp[i][flag]!=-1)
        {
            return dp[i][flag];
        }
        if(dp[i][flag]==-1)
        {
            
        if(flag==0) // buy stock
        {
            int opt1=answer(prices,1,i+1,c,dp)-prices[i]; // buy
            int opt2=answer(prices,0,i+1,c,dp);   // ignore
                res= max(opt1,opt2);
        }
        else if(flag==1) // sell stock
        {
            int opt1=answer(prices,0,i+1,c+1,dp) + prices[i]; // sell
            int opt2=answer(prices,1,i+1,c,dp);   // ignore
            res= max(opt1,opt2);
        }
            dp[i][flag]=res;
        
        }
        return res;
        
    }
    int maxProfit(vector<int>& prices) {
        int flag=0;  // initially flag is 0 i.e we need to buy stock
        int i=0;
        int c=0;  // count as we can only buy and sell one stock
        int n=prices.size();
        int dp[n+1][3];    // dp of flag and array size
        memset(dp,-1,sizeof(dp));
        return answer(prices,flag,i,c,dp);
        
    }
};
**********************************************************
2] BEST TIME TO BUY AND SELL STOCK 2

Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.

Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

 

Constraints:

    1 <= prices.length <= 3 * 10 ^ 4
    0 <= prices[i] <= 10 ^ 4


class Solution {
public:
    int answer(vector<int>& prices,int flag,int i,int dp[][3])
    {
        int l=prices.size();
        if(i>=l )
        {
            return 0;
        }
        int res=0;
        if(dp[i][flag]!=-1)
        {
            return dp[i][flag];
        }
        if(dp[i][flag]==-1)
        {
            
        if(flag==0) // buy stock
        {
            int opt1=answer(prices,1,i+1,dp)-prices[i]; // buy
            int opt2=answer(prices,0,i+1,dp);   // ignore
                res= max(opt1,opt2);
        }
        else if(flag==1) // sell stock
        {
            int opt1=answer(prices,0,i+1,dp) + prices[i]; // sell
            int opt2=answer(prices,1,i+1,dp);   // ignore
            res= max(opt1,opt2);
        }
            dp[i][flag]=res;
        
        }
        return res;
        
    }
    int maxProfit(vector<int>& prices) {
        int flag=0;  // initially flag is 0 i.e we need to buy stock
        int i=0;
      // WE CAN BUY AS MANY STOCKS
        int n=prices.size();
        int dp[n+1][3];    // dp of flag and array size
        memset(dp,-1,sizeof(dp));
        return answer(prices,flag,i,dp);
        
    }
};
