Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


*************************
class Solution {
public:
// time=0(n)
// space=0(1)
    int maxProduct(vector<int>& nums) {
       int ans=INT_MIN;
       int max_so_far=1,min_so_far=1;
       for(int i=0;i<nums.size();i++)
       {
            if(nums[i]<0){  // if -ve
               // nums[i]<0
                swap(max_so_far,min_so_far);
            }
           // for greater than equal to 0
           // checking max and min till this point
             max_so_far=max(nums[i],max_so_far*nums[i]);
             min_so_far=min(nums[i],min_so_far*nums[i]);
             ans=max(ans,max_so_far);
       }
        return ans;
    }
};
