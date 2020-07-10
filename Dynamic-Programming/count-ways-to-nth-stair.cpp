/*

Count ways to Nth stair(order does not matter)

There are N stairs, and a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. Count the number of ways,
the person can reach the top (order does not matter).
Note: Order does not matter means for n=4 {1 2 1},{2 1 1},{1 1 2} are considered

Input:
2
4
5
Output:
3
3

*/

#include <iostream>
#include<string.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    if(n==1 || n==2 || n==0)
	    printf("%d\n",n);
	    else
	    {
    	    int dp[n+1];
    	    memset(dp,0,sizeof(dp));
    	    dp[1] = 1;
    	    dp[2] = 2;
    	    for(int i=3;i<=n;i++)
    	    {
    	        if(i%2==0)
    	            dp[i] = dp[i-1]+1;
    	        else
    	            dp[i] = dp[i-1];
    	    }
    	    printf("%d\n",dp[n]);
	    }
	    
	}
	return 0;
}
