/*
Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

Input:
2
4
1 6 5 11
4
36 7 46 40

Output : 
1
23
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    int sum = 0;
	    for(int i=0;i<n;i++)
	    {
	        sum = sum + arr[i];
	    }
	    int dp[n+1][sum+1];
	    for(int i=0;i<=n;i++)
	    {
	        dp[i][0] = 1;
	    }
	    for(int j=1;j<=sum;j++)
	    {
	        dp[0][j] = 0;
	    }
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            dp[i][j] = dp[i-1][j];
	            if(arr[i-1]<=j)
	            dp[i][j] = dp[i][j] | dp[i-1][j-arr[i-1]];
	        }
	    }
	    
	    int minm = INT_MAX;
	    for(int j=sum/2;j>=0;j--)
	    {
	        if(dp[n][j]==1)
	        {
	            minm = min(minm,sum-2*j);
	            break;
	        }
	    }
	    cout<<minm<<'\n';
	}
	return 0;
}
