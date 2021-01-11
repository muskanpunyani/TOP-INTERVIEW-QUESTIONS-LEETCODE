Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Follow up:

    Could you solve this problem without using the library's sort function?
    Could you come up with a one-pass algorithm using only O(1) constant space?

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

Example 3:

Input: nums = [0]
Output: [0]

Example 4:

Input: nums = [1]
Output: [1]

 

Constraints:

    n == nums.length
    1 <= n <= 300
    nums[i] is 0, 1, or 2.



***********************************************************
/*
i/p=[1,2,0]
1    2     0
L,M        H

M=1
M++


1    2     0
L    M    H
    
M=2
swap(nums[l],nums[h])
H--

1    0      2
L     H,M
M=0
swap(nums[l],nums[M])
M++
L++

0    1     2
     L,H    M
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // we will take mid,low,high
        // mid and low point to start and high point to end
        // while mid<=high
        // distributed in 3 parts 0,1,2
        // 0 will be at start, 2 at end and 1 in bn which specifies mid
        // so whenever we get 1,dont need to do anything just mid++
        // whenever we get 0 at mid,it should be at low,therefore swap mid and low and incremnt mid and low
        // whenever we get 2 at mid,it should be at last,i.e swap mid and high and decremnt high,dont increment mid
        
        int low=0,mid=0;
        int high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==1)
                mid++;
            else if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
        
    }
};
/*
1] NEED TO INCREMENT BOTH L AND M  (MID=0) 
2] NEED TO DECREMNT ONLY H         (MID=2)
3] NEED TO INCREMNT ONLY M          (MID=1)
*/
