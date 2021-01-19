Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]

Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)


****************************************
class Solution {
public:
    /*
    eg= i/p=1 2 3 4
    left= 1 1 2 6     // take oth elem as 1 
    1st elem=1*1=1
    2nd= 1*2=2
    3rd=2*3=6
    
    right= 24 12 4 1  // take last elem as 1
    2nd last=1*4=4...
    
    
    similar,multiply let and right for every index and that is ans
    will do this here using only 1 array 
    
    */
    // time=0(n)
    // space=0(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
       vector<int> ans(n,1);
       ans[0]=1;           // for left
        for(int i=0;i<n-1;i++)
        {
            ans[i+1]=ans[i]*nums[i];
        }
        // for right
        // for only 1 arr, we need to know the prev mul factor
        int prev=1;
        ans[n-1]=ans[n-1]*1;
        for(int j=n-2;j>=0;j--)
        {
            ans[j]=prev*nums[j+1]*ans[j];
            prev=prev*nums[j+1];
        }
        return ans;
    }
};
