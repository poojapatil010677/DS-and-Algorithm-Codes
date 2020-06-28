/*

Path in Matrix

Given a N X N  matrix Matrix[N][N] of positive integers.
There are only three possible moves from a cell Matrix[r][c].

1. Matrix[r+1][c]

2. Matrix[r+1][c-1]

3. Matrix[r+1][c+1]

Starting from any column in row 0, return the largest sum of any 
of the paths up to row N-1.

Input:
1
2
348 391 618 193

Output:
1009

*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    int arr[n][n];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            scanf("%d",&arr[i][j]);
	        }
	    }
	    
	    int dp[n+1][n+2];
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=n+1;j++)
	        {
	            if(i==0 || j==0 || j==n+1)
	                dp[i][j] = 0;
	           else
	           {
	               dp[i][j] = max(dp[i-1][j-1],dp[i-1][j+1]);
	               dp[i][j] = max(dp[i][j],dp[i-1][j]) + arr[i-1][j-1];
	           }
	        }
	    }
	    int res = 0;
	    for(int i=0;i<=n;i++)
	    {
	        res = max(res,dp[n][i]);
	    }
	    cout << res << "\n";
	}
	return 0;
}

