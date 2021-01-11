Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:

    A straight forward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?

 

Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

 

Constraints:

    m == matrix.length
    n == matrix[0].length
    1 <= m, n <= 200
    -231 <= matrix[i][j] <= 231 - 1


**************************************
class Solution {
public:
    // 0(n2) time
    // 0(1) space
    void setZeroes(vector<vector<int>>& matrix) {
        // we will use 1st row and 1st col as marker for 0
        // first we will check whether there is 0 in first row or col so that they can be modified later
        // for every 0 we will mark its 1st row n col as 0
        // now for every i,j if it contains zero in first row or col then that index is made 0
        // if 1st row or col were containing 0 initially then make changes to that too
        int n=matrix.size();
        int m=matrix[0].size();
        int zero_row=false;      // checking zero in first row
        int zero_col=false;      // checking 0 in first col
        for(int i=0;i<m;i++)
        {
            if(matrix[0][i]==0)
                zero_row=true;
        }
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==0)
                zero_col=true;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==0)  // for every 0 mark in first row n col
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
       for(int i=1;i<n;i++ )
       {
           for(int j=1;j<m;j++)
           {
               if(matrix[i][0]==0 || matrix[0][j]==0) // change the matrix if 0 is present
               {
                   matrix[i][j]=0;
               }
           }
       }
      if(zero_row)   // handle for first row
      {
           for(int i=0;i<m;i++)
           {
           matrix[0][i]=0;
            }  
      }
      if(zero_col)    // handle for first col
      {
          for(int i=0;i<n;i++)
          {
              matrix[i][0]=0;
          }
      }
      
        
    }
};
