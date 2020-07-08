/*

Edit Distance

Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace

All of the above operations are of cost=1.

*/

#include <iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n1,n2;
	    scanf("%d %d",&n1,&n2);
	    char s1[n1],s2[n2];
	    scanf("%s %s",s1,s2);
	    int dp[n1+1][n2+1];
	    memset(dp,0,sizeof(dp));
	    for(int i=0;i<=n1;i++)
	    {
	        for(int j=0;j<=n2;j++)
	        {
	            if(i==0)
	                dp[i][j] = j;
	            else if(j==0)
	                dp[i][j] = i;
	            else if(s1[i-1]==s2[j-1])
	                dp[i][j] = dp[i-1][j-1];    
	            else
	                dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
	        }
	    }
	    printf("%d\n",dp[n1][n2]);
	}
	return 0;
}
