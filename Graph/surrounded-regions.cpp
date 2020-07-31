/*

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

*/

class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j,int n,int m)
    {
        if(i>=n || j>=m || i<0 || j<0 || board[i][j]=='X' || board[i][j]==' ')
            return;
        else
        {
            board[i][j] = ' ';
            dfs(board,i-1,j,n,m);
            dfs(board,i+1,j,n,m);
            dfs(board,i,j+1,n,m);
            dfs(board,i,j-1,n,m);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n==0) return;
        int m = board[0].size();
        //if(n==0 && m==0) return;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O')
                    dfs(board,i,j,n,m);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                    board[i][j] = 'X';
                if(board[i][j]==' ')
                    board[i][j] = 'O';
            }
        }
    }
};
