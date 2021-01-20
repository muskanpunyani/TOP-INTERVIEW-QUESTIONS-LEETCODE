Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

 

Constraints:

    1 <= nums.length <= 2500
    -104 <= nums[i] <= 104

 

Follow up:

    Could you come up with the O(n2) solution?
    Could you improve it to O(n log(n)) time complexity?


*****************************
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // o(nlogn)
        //take a dp array initially empty
        // find the element in dp arr which is greater than nums[i]
        // if no greater elemnt exist in dp than nums[i],then put nums[i] to dp
        // if gretaer already exists,we cant put this elementt as subsequence will not be increasing,
        // so we will relace that greater element with nums[i] (i.e smaller element),as putting smaller elemnent
        // will lead to greater length
        // return length of dp array as output
        vector<int> dp;
        for(int i=0;i<nums.size();i++)
        {
            auto it=lower_bound(dp.begin(),dp.end(),nums[i]);
            if(it==dp.end()) // i.e greater elemnt not found
            {
                dp.push_back(nums[i]);
            }
            else{
                *it=nums[i];  // if greater found,put smaller at that index
            }
        }
        return dp.size();
    }
};
