/*

Word Search

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

*/

class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int p)
    {
        if(p==word.length()) return true;
        
        else if(i<0 || j<0 || i>=board.size() || j>=board[i].size() || board[i][j]!=word[p])
            return false;
        
        char temp = board[i][j];
        board[i][j] = ' ';
        bool res = dfs(board,word,i+1,j,p+1) ||
           dfs(board,word,i-1,j,p+1) ||
           dfs(board,word,i,j+1,p+1) ||
           dfs(board,word,i,j-1,p+1);   
        board[i][j] = temp;
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int j=0;j<board.size();j++)
        {
            for(int k=0;k<board[j].size();k++)
            {
                if(board[j][k]==word[0] && dfs(board,word,j,k,0))
                {
                        return true;
                }
            }
        }
        return false;
    }
};
