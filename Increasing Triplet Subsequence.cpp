Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.

Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.

Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

 

Constraints:

    1 <= nums.length <= 105
    -231 <= nums[i] <= 231 - 1

 
Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?
**************************
class Solution {
public:
// time=0(n)
    bool increasingTriplet(vector<int>& nums) {
        // it is same as longest increasing subsequence,just the subseq size need to be,can do it in that way but time=0(nlogk)
        // we will do this byanother method
        // take two values and check if the incoming elem is smaller than one of them or both of them,if not means it is gretaer than start 2,means soln exist
        
        int first=INT_MAX;
        int second=INT_MAX;
        for(int third:nums)
        {
            if(third<=first)  // if less than first,change first new start
                first=third;
            else if(third<=second) // if less than second,change only second as greater than first
                second=third;
            else                 //not less than first and second,means increasing found first<second<third
                return true;
        }
        return false;
    }
};
