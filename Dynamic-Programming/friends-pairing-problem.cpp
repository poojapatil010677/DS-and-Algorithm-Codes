/*
Friends Pairing Problem

Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

Examples:

Input  : n = 3
Output : 4
Explanation
{1}, {2}, {3} : all single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.

*/

#include <iostream>
using namespace std

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    if(n==0 || n==1)
	        printf("%d",1);
	   else
	   {
	    long long int dp[n+1];
	    dp[0] = 1;
	    dp[1] = 1;
	    for(int i=2;i<=n;i++)
	    {
	        dp[i] = (dp[i-1]%1000000007) + (((i-1)*dp[i-2])%1000000007);
	    }
	    printf("%ld",dp[n]%1000000007);
	   }
	   printf("\n");
	}
	return 0;
}
