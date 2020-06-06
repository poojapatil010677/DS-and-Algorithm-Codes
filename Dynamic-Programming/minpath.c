/*

Number of unique paths

Given a M X N matrix with your initial position at top-left cell, find the 
number of possible unique paths to reach the bottom right cell of the matrix
from the initial position.

*/

#include <stdio.h>

int main() {
	//code
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,m;
	    scanf("%d %d",&n,&m);
	    int dp[n][m];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(i==0 || j==0)
	                dp[i][j] = 1;
	            else
	            {
	                dp[i][j] = dp[i-1][j] + dp[i][j-1];
	            }
	        }
	    }
	    printf("%d\n",dp[n-1][m-1]);
	}
	return 0;
}
