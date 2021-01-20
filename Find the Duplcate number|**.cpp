Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

Example 2:

Input: nums = [3,1,3,4,2]
Output: 3

Example 3:

Input: nums = [1,1]
Output: 1

Example 4:

Input: nums = [1,1,2]
Output: 1

 

Constraints:

    2 <= n <= 3 * 104
    nums.length == n + 1
    1 <= nums[i] <= n
    All the integers in nums appear only once except for precisely one integer which appears two or more times.

 

Follow up:

    How can we prove that at least one duplicate number must exist in nums?
    Can you solve the problem without modifying the array nums?
    Can you solve the problem using only constant, O(1) extra space?
    Can you solve the problem with runtime complexity less than O(n2)?


*************************************
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // no are in range 1 to n-1
        // only 1 duplicate exist
        // we will mark the index of visited val as -ve and if -ve index again arised,means repeated thus break
        // time=0(n)
        // space=0(1)
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int val=abs(nums[i]);
            if(nums[val] > 0)
            {
                nums[val]=-nums[val];
            }
            else{
             ans=abs(nums[i]);
             break;
            }
        }
        return ans;
    }
};
