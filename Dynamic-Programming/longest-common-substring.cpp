#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n1,n2;
	    cin>>n1>>n2;
	    string s1,s2;
	    cin>>s1>>s2;
	    int dp[n1+1][n2+1];
	    int res = 0;
	    memset(dp,0,sizeof(dp));
	    for(int i=1;i<=n1;i++)
	    {
	        for(int j=1;j<=n2;j++)
	        {
	            if(s1[i-1]==s2[j-1])
	            {
	                dp[i][j] = dp[i-1][j-1] + 1;
	                res = max(res,dp[i][j]);
	            }
	            else
	            dp[i][j] = 0;
	        }
	    }
	    cout<<res<<'\n';
	}
	return 0;
}
