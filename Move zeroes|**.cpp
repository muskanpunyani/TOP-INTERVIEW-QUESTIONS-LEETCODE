Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.

*********************************
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int zero_pos=0;
        // time=0(n)
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)  // if no is not zero,swap it with the position of 0th elem
            {
                swap(nums[zero_pos],nums[i]);
                zero_pos++;
            }
        }
        
    }
};
