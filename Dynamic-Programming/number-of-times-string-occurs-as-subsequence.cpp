/*

Find number of times a string occurs as a subsequence

Given two strings S1 and S2, find the number of times the second string occurs 
in the first string, whether continuous or discontinuous.

Example:

Input:

1
13 3
geeksforgeeks gks

Output: 

4

*/

#include <iostream>
#include <string.h>
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
	    memset(dp,0,sizeof(dp));
	    for(int i=0;i<n1;i++)
	        dp[i][0] = 1;
	    for(int i=1;i<n2;i++)
	        dp[0][i] = 0;
	   for(int i=1;i<=n1;i++)
	   {
	       for(int j=1;j<=n2;j++)
	       {
	           if(s1[i-1]==s2[j-1])
	           {
	               dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
	           }
	           else
	           {
	               dp[i][j] = dp[i-1][j];
	           }
	       }
	   }
	   cout<<dp[n1][n2]<<'\n';
	}
	return 0;
}
