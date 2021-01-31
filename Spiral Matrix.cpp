Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 10
    -100 <= matrix[i][j] <= 100


*************************************************
class Solution {
public:
    // time=0(n2)
    // space=0(1)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       vector<int> ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int dir=1;              // dir 1 from ( -> ) upper top row
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=m-1;
       while(left<=right && top<=bottom)
       {
           if(dir==1)                        // ->
           {
               for(int i=left;i<=right;i++)
               {
                   ans.push_back(matrix[top][i]);
               }
               top++;
               dir=2;
           }
           else if(dir==2)                   // |
           {
               for(int i=top;i<=bottom;i++)
               {
                   ans.push_back(matrix[i][right]);
               }
               right--;
               dir=3;
           }
            else if(dir==3)                   // <--
           {
               for(int i=right;i>=left;i--)
               {
                   ans.push_back(matrix[bottom][i]);
               }
               bottom--;
               dir=4;
           }
            else if(dir==4)                   // |^
           {
               for(int i=bottom;i>=top;i--)
               {
                   ans.push_back(matrix[i][left]);
               }
               left++;
               dir=1;
           }
       }
        return ans;
    }
};
