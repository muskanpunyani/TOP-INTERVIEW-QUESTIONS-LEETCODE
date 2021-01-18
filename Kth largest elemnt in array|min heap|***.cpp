Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

**************************
class Solution {
public:
    /*
    Time Complexity: O(k + (n-k)Logk) without sorted output. If sorted output is needed then O(k + (n-k)Logk + kLogk)
    */
    int findKthLargest(vector<int>& nums, int k) {
       // we will create a min heap of size k and insert elemnts in it
        // we will insert the elemt only if it is greater than heaps top
        // in end,top of heap will be kth largest
        priority_queue<int,vector<int>,greater<int>> min_heap;
        for(int i=0;i<k;i++)    // push starting k elemnts on heap
        {
            min_heap.push(nums[i]);
        }
        
        for(int i=k;i<nums.size();i++) //for elemnts k to n-1
        {
            if(nums[i] >min_heap.top())  // if num is greater,then push onto heap
            {
                    min_heap.pop();      // pop the topmost elem as heap should only be of size k    
                    min_heap.push(nums[i]);
            }
        }
        return min_heap.top();  // top will be ans
    }
};
