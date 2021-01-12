Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

**********************************************
class Solution {
public:
    // time=0(m*n)
    // we will take the 'O' of all borders and make the neighbours as well as border
    // 'O' to *
    // rest all 'o' are changed to 'x' and the '*' ones to 'o'
    void dfs(vector<vector<char>>& board,int row,int col)
    {
        int n=board.size();
        int m=board[0].size();
        if(row<0 || row>=n || col<0 || col>=m || board[row][col]!='O')
        {
            return;
        }
        if(board[row][col]=='O')
        {
            board[row][col]='*';
            dfs(board,row+1,col);
            dfs(board,row-1,col);
            dfs(board,row,col+1);
            dfs(board,row,col-1);
        }
    }
    void solve(vector<vector<char>>& board) {
        // border 0's and 0's connected to border 0 are not changed
        int n=board.size();
        if(n==0)
            return;
        int m=board[0].size();
        for(int i=0;i<m;i++) // 1st row containing zero
        {
            if(board[0][i]=='O')
            {
                dfs(board,0,i);
            }
        }
        for(int i=0;i<m;i++) // last row containing 0
        {
            if(board[n-1][i]=='O')
            {
                dfs(board,n-1,i);
            }
        }
        for(int i=0;i<n;i++)      //1st col containing 0
        {
            if(board[i][0]=='O')
            {
                dfs(board,i,0);
            }
        }
        for(int i=0;i<n;i++)    // last col containing 0
        {
            if(board[i][m-1]=='O')
            {
                dfs(board,i,m-1);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(board[i][j]=='*')  // * are made to 0
                   board[i][j]='O';
                 else
                    board[i][j]='X';   // rest all to x
                
            }
        }
    }
};
