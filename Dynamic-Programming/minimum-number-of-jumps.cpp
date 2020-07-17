/*

Minimum Number of Jumps

Given an array of integers where each element represents the max number of steps 
that can be made forward from that element. The task is to find the minimum number 
of jumps to reach the end of the array (starting from the first element). If an 
element is 0, then cannot move through that element.

Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
Output:
3
2

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&arr[i]);
	    }
	    if(arr[0]==0)
	    cout << -1 <<"\n";
	    else
	    {
    	    int dp[n];
    	    dp[0] = 0;
    	    for(int i=1;i<n;i++)
    	    {
    	        dp[i] = INT_MAX;
    	        for(int j=0;j<i;j++)
    	        {
    	            if(arr[j]!=0 && j+arr[j]>=i && dp[j]+1<dp[i])
    	                dp[i] = dp[j] + 1;
    	        }
    	        if(dp[i]==INT_MAX) dp[i] = -1;
    	    }
    	    cout << dp[n-1]<<'\n';
	    }
	}
	return 0;
}

