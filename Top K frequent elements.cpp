Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
    It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
    You can return the answer in any order.


****************************
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1st soln to use max heap 0(nlogk),create a map with freq and then put them in heap,pop top elem i.e with highest freq till k
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>> q; // max heap,first elem is freq and second is value
        for(auto it=m.begin();it!=m.end();it++)
        {
             q.push({it->second,it->first});
        }
        vector<int> ans;
        while(k--)   //pop top elem with max freq till k
        {
            pair<int,int> p=q.top();
            ans.push_back(p.second);  // p.second is val
            q.pop();
        }
        return ans;
        
    }
};
