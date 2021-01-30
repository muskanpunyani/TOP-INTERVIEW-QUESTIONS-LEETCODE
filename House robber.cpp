Medium

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically 
contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.

 

Constraints:

    0 <= nums.length <= 100
    0 <= nums[i] <= 400


*************************************
class Solution {
public:
    /*
The trick is the dp[i] = Math.max(dp[i - 2] + nums[i], dp[i - 1]) statement (Phase of Transfer Function).

Statemet 	          Description
dp[i - 2] + nums[i] 	Rob
dp[i - 1] 	           No Rob
    */
    int rob(vector<int>& nums) {
        //pehla liya to uska neighbor ni le skti,mtlb ya to 1st ya to uska neighbor
        /*
        1] rob or no rob from a particular house
        2] if rob,nums[i]+nums[i-2]
        3] if not rob, nums[i-1], dont take nums[i]
        4] the elemt at last place of dp array is ans
        eg.dp=nums= 2 1 1 2
        0th elem will remain same
        dp[1]=max(dp[0],dp[1])=max(2,1)=2
        therefore, dp=2 2 1 2
        now for 2 to n-1
        dp[2]= either take house at index 2 or dont take it
        dp[2]=max(dp[2]+d[2-2],dp[2-1])
        max(1+2,2)=3
        now dp= 2 2 3 2
        dp[3]=max(dp[3]+dp[3-2],dp[3-1])
        max(2+2,3)=4
        dp[3]=4
        
        dp=2 2 3 4
        ans=4
        */
        // at every index we are finding max till that index
        //. time=0(n)
        if(nums.size()==0)
            return 0;
        if(nums.size()>1)
        nums[1]=max(nums[1],nums[0]); // max of 0th and 1th will be max till 1  
        for(int i=2;i<nums.size();i++)
        {
           nums[i]=max(nums[i]+nums[i-2],nums[i-1]);  //skip adj    
            //either take nums[i] or dont take it
        }
      
       int  ans=nums[nums.size()-1];  // max till last is ans
        return ans;
    }
};
