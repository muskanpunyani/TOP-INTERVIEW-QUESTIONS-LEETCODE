Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

 

Constraints:

    1 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= starti <= endi <= 104



******************************************
bool compare(vector<int> v1,vector<int> v2)
    {
        return v1[0]<v2[0];
    }
class Solution {
public:
   
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort in increasing order of start
        if(intervals.size()<=1)
        {
            return intervals;
        }
        sort(intervals.begin(),intervals.end(),compare);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]); // push 1st
        for(int i=1;i<intervals.size();i++)
        {
           if(ans.back()[1]>=intervals[i][0]) // end is greater than start of another interval,i.e overlap
           {
               int c=intervals[i][1];
               int v=ans.back()[1];
               ans.back()[1]=max(v,c);   // change the end
           }
            else{
                ans.push_back(intervals[i]);    // no overlap put directly
            }
        }
        return ans;
    }
};
