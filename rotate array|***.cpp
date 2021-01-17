Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

    Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
    Could you do it in-place with O(1) extra space?

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

 

Constraints:

    1 <= nums.length <= 2 * 104
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 105


********************************
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
       //1] traverse array from last, till k elements and remove evry elemnt and insert it to front of array, 
        based on the approach that when we rotate the array k times,k elemnts from the back end of the array come at front and rest of elemnt from front shift backwards
        eg list= 1 2 3 4 5 6 7
        k=3
        1. reverse all numbers: 7 6 5 4 3 2 1
        2. reversing first k no : 5 6 7 4 3 2 1
        3. reversing last n-k numbers : 5 6 7 1 2 3 4
        list-> reverse list->reverse first k->reverse n-k remaining
        time=0(n)
        space=0(1)
         */ 
        int n=nums.size();
        reverse(nums.begin(),nums.end());
        // k elemnts
        reverse(nums.begin(),nums.begin()+k%n);//%n bcz it can exceed the length of array
        reverse(nums.begin()+k%n,nums.end()); // n-k elements
        
    }
};
