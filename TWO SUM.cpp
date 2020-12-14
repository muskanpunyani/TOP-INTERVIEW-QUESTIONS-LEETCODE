Easy

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

 

Constraints:

    2 <= nums.length <= 103
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.



*****************************************************
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 0(n) space and o(n) time
        // initially nothing in map,we are adding as per traversal
        // if a value is in map,i.e occured before
        int n=nums.size();
        unordered_map<int,int> m;  // map of value and index
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int val=nums[i];
            int rem=target-val;
            if(m.find(rem)!=m.end()) // i.e rem found in map
            {
                ans.push_back(m[rem]);  // we got our answer
                ans.push_back(i);
                break;
            }
            else{
                m[val]=i;    // else push the values to map
            }
        }
        return ans;
    }
};
