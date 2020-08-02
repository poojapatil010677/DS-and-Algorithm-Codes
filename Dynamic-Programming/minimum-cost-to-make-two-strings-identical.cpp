/*

Minimum Cost To Make Two Strings Identical 

Given two strings X and Y, and two values costX and costY. We need to find minimum cost required to make the given two strings identical. We can delete 
characters from both the strings. The cost of deleting a character from string X is 
costX and from Y is costY. Cost of removing all characters from a string is same.

Input:

1

10 20

abcd acdb

Output:

30

*/

#include <iostream>
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
	    int l1 = s1.length();
	    int l2 = s2.length();
	    int dp[l1+1][l2+1];
	    for(int i=0;i<=l1;i++)
	    {
	        for(int j=0;j<=l2;j++)
	        {
	            if(i==0)
	                dp[i][j] = j*n2;
	            else if(j==0)
	                dp[i][j] = i*n1;
	            else if(s1[i-1]==s2[j-1])
	                dp[i][j] = dp[i-1][j-1];
	            else
	            {
	                dp[i][j] = min(dp[i-1][j]+n1,dp[i][j-1]+n2);
	            }
	        }
	    }
	    cout<<dp[l1][l2]<<'\n';
	}
	return 0;
}

