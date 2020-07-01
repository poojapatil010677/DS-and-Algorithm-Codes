/*

Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in 
the diagram below).

The robot can only move either down or right at any point in time. The robot 
is trying to reach the bottom-right corner of the grid (marked 'Finish' in 
the diagram below).

How many possible unique paths are there?

*/

int uniquePaths(int m, int n) {
        if(n==0 || m==0) return 0;
        
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0 || i==0) dp[i][j] = 1;
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }

