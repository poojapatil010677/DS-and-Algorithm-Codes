/*

Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the
diagram below).

The robot can only move either down or right at any point in time. The robot is 
trying to reach the bottom-right corner of the grid (marked 'Finish' in the 
diagram below).

Now consider if some obstacles are added to the grids. How many unique paths 
would there be?

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2

*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        if(g[0][0]==1) return 0;
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        int tempi = 1;
        int tempj = 1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0) 
                {
                    if(g[i][j]==1)
                        tempi = 0;
                    dp[i][j] = tempi;
                }
                else if(j==0)
                {
                    if(g[i][j]==1)
                        tempj = 0;
                    dp[i][j] = tempj;
                }
                else if(g[i][j]==1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

