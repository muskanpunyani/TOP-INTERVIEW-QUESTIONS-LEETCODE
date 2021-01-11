Given an m x n board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

 

Constraints:

    m == board.length
    n = board[i].length
    1 <= m, n <= 200
    1 <= word.length <= 103
    board and word consists only of lowercase and uppercase English letters.


****************************************************
/*
space complexity O(Length of longest word) as space complexity = depth of recursion tree. Time complexity = O(n * m * 4^L) , where L = length of longest word. (as in every recursive call, we are calling the function 4 times, thus exponential complexity).
*/
class Solution {
public:
  bool findwhole(int row,int col,vector<vector<char>>& board,string word,int n,int m,int level)
    {
      int l=word.length();
      if(level==l)   //means whole string is covered
      {
          return true;
      }
      if(row<0 || col <0 || row>=n || col>=m)
      {
          return false;
      }
      if(board[row][col]==word[level] && board[row][col]!='#') // i.e the char matches
      {
          char temp=board[row][col];
          board[row][col]='#'; //mark it as visited
              //bitwise or (any dirn to be true)
          bool ans=false;
     ans= findwhole(row-1,col,board,word,n,m,level+1) || findwhole(row+1,col,board,word,n,m,level+1) || findwhole(row,col-1,board,word,n,m,level+1) || findwhole(row,col+1,board,word,n,m,level+1);
          
          board[row][col]=temp;     //mark that as unvisited again
          return ans;
      }
      else{
      return false;
      }
      
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();  //row
        int m=board[0].size();  //col
        int l=word.length();
        if(l > (n*m))
        {
            return false;
        }
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(word[0]==board[i][j])  // if first char is found
               {
                  if( findwhole(i,j,board,word,n,m,0))  // traverse for whole dfs
                  {
                      return true;
                      break;
                      
                  }
               }
           }
       }
        return false;
        
    }
};
