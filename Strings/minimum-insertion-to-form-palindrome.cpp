/*

Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Input:
3
abcd
aba
geeks

Output:
3
0
3
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int n = s.length();
	    int dp[n+1][n+1];
	    memset(dp,0,sizeof(dp));
	    for(int l=2;l<=n;l++)
	    {
	       for(int i=1;i<=n-l+1;i++)
	       {
	           int j = i+l-1;
	           if(s[i-1]==s[j-1])
	                dp[i][j] = dp[i+1][j-1];
	           else
	                dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1;
	       }
	    }
	    cout<<dp[1][n]<<'\n';
	}
	return 0;
}
