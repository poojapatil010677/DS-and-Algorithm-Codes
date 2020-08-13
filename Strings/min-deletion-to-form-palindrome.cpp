/*

Given a string of S as input. Your task is to write a program to remove or delete minimum number of characters from the string so that the resultant string is palindrome.

Note: The order of characters in the string should be maintained.

Input:
2
aebcbda
geeksforgeeks
Output:
2
8

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
	        for(int i=0;i<n-l+1;i++)
	        {
	            int j = i+l-1;
	            if(s[i]==s[j] && l==2)
	            {
	                dp[i][j] = 0;
	            }
	            else
	            {
	                if(s[i]==s[j])
	                {
	                    dp[i][j] = dp[i+1][j-1];
	                }
	                else
	                {
	                     dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1;
	                }
	                
	            }
	        }
	    }
	   /* for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=n;j++)
	        {
	            cout<<dp[i][j]<<' ';
	        }
	        cout<<'\n';
	    }*/
	    cout<<dp[0][n-1]<<'\n';
	}
	return 0;
}
