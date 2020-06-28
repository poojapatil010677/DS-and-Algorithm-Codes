/*

Largest square formed in a matrix

Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

Input:
3
5 6
0 1 0 1 0 1 1 0 1 0 1 0 0 1 1 1 1 0 0 0 1 1 1 0 1 1 1 1 1 1
2 2
1 1 1 1
2 2
0 0 0 0

Output:
3
2
0

*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,m;
	    scanf("%d %d",&n,&m);
	    int arr[n][m];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            scanf("%d",&arr[i][j]);
	        }
	    }
	    
	    int maxm = 0;
	    int dp[n+1][m+1];
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=m;j++)
	        {
	            if(i==0 || j==0)
	                dp[i][j] = 0;
	            else if(arr[i-1][j-1]==1)
	            {
	                dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
	                dp[i][j] = min(dp[i][j],dp[i-1][j-1])+1;
	                maxm = max(dp[i][j],maxm);
	            }
	            else
	            {
	                dp[i][j] = 0;
	            }
	        }
	    }
	    
	    cout << maxm << '\n';
	    
	}
	return 0;
}
