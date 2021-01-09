Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.

 

Example 1:

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

 

Constraints:

    board.length == 9
    board[i].length == 9
    board[i][j] is a digit or '.'.



***************************************************
class Solution {
public:
    bool issaferow(vector<vector<char>>& board,int row,int num)
    {
        // if this no is not present twice in row
        int c=0;
        for(int i=0;i<9;i++)
        {
            if((board[row][i]-'0')==num)
                c++;
        }
        if(c>1)
            return false;
        return true;
        
    }
      bool issafecol(vector<vector<char>>& board,int col,int num)
    {
        // if this no is not present twice in col
        int c=0;
        for(int i=0;i<9;i++)
        {
            if((board[i][col]-'0')==num)
                c++;
        }
        if(c>1)
            return false;
        return true;
        
    }
      bool issafegrid(vector<vector<char>>& board,int row,int col,int num)
    {
        // if this no is not present twice in 3*3 grid
        int c=0;
          int row_factor=row-(row%3);
          int col_factor=col-(col%3);
          for(int i=0;i<3;i++)
          {
              for(int j=0;j<3;j++)
              {
                  if((board[i+row_factor][j+col_factor]-'0')==num)
                  {
                      c++;
                  }
              }
          }
        if(c>1)
            return false;
        return true;
        
    }
    
    bool safe(vector<vector<char>>& board,int row,int col,int num)
    {
        if(issaferow(board,row,num)&& issafecol(board,col,num)&& issafegrid(board,row,col,num))
        {
            return true;
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]>='0' && board[i][j]<='9'){ // if digit
                int num=board[i][j]-'0';
                if(!safe(board,i,j,num))
                {
                    return false;
                }
                }
            }
        }
        return true;
    }
    
};
