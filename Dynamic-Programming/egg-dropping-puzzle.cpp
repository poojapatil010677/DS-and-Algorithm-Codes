// Egg Dropping Puzzle

#include <iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int e,f;
	    cin>>e>>f;
	    int dp[e+1][f+1];
	    memset(dp,0,sizeof(dp));
	    for(int i=1;i<=f;i++)
	        dp[1][i] = i;
	    for(int i=1;i<=e;i++)
	        dp[i][1] = 1;
	    for(int i=2;i<=e;i++)
	    {
	        for(int j=2;j<=f;j++)
	        {
	            dp[i][j] = INT_MAX;
	            for(int k=1;k<=j;k++)
	            {
	                int res = 1 + max(dp[i-1][k-1],dp[i][j-k]);
	                if(res<dp[i][j])
	                    dp[i][j] = res;
	            }
	        }
	    }
	    cout<<dp[e][f]<<'\n';
	}
	return 0;
}
