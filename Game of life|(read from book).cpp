According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

    Any live cell with fewer than two live neighbors dies as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population.
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

 

Example 1:

Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

Example 2:

Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]

 

Constraints:

    m == board.length
    n == board[i].length
    1 <= m, n <= 25
    board[i][j] is 0 or 1.

 

Follow up:

    Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
    In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?



******************************************
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int x[8]={0,1,1,1,0,-1,-1,-1};
        int y[8]={1,1,0,-1,-1,-1,0,1};
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int live=0;   // no of live neighbors
                for(int k=0;k<8;k++)
                {
                    int row=x[k]+i;
                    int col=y[k]+j;
                    if(row>=0 && row<n && col>=0 && col<m && (board[row][col]==1 || board[row][col]==-1))
                    {
                        live++;
                    }
                }
                if(board[i][j]==1 && ((live<2) || (live>3)))
                {
                    //board[i][j]=0;
                    board[i][j]=-1;
                }
                else if(board[i][j]==1 && (live==2 || live==3))
                {
                    board[i][j]=1;
                }
                else if(board[i][j]==0 && live==3)
                {
                    //board[i][j]=1;
                    board[i][j]=2;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==-1)
                    board[i][j]=0;
                else if(board[i][j]==2)
                    board[i][j]=1;
            }
        } 
    }
};
