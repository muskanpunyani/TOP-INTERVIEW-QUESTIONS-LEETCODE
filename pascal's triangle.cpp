Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]



*****************************************
class Solution {
public:
    // dp
    // 0(numRows^2) = time& space
    // every row will contain 1 at begin and at end and the mid values are sum of prev 2 vals of prev row
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows==0)
            return ans;
        ans.push_back({1});   // 1st row
        for(int i=1;i<numRows;i++) // 0 based indexing
        {
            vector<int> row;
            vector<int> prev_row=ans[i-1];  // extracting prev row
            row.push_back(1);               // 1 at start
            for(int j=1;j<i;j++)            // evaluate values for this row using prev rows
            {
                row.push_back(prev_row[j-1]+prev_row[j]);
            }
            row.push_back(1);         // 1 at end
            ans.push_back(row);
        }
        return ans;
       
    }
};
