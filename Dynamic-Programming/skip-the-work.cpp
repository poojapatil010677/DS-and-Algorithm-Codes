/*
Given an array A[ ] denoting the time taken to complete N tasks, determine the 
minimum amount of time required to finish the tasks considering that you can 
skip any task, but skipping two consecutive tasks is forbidden.

Input
4
4
10 5 7 10
6
5 6 7 8 9 10
2
10 20
5
22 10 15 3 5

Output
12
21
10
13

*/

#include <iostream>
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
	    int dp[n+1];
	    dp[0] = 0;
	    dp[1] = arr[0];
	    for(int i=2;i<=n;i++)
	    {
	        dp[i] = min(dp[i-1],dp[i-2])+arr[i-1];
	    }
	    cout <<min(dp[n],dp[n-1])<<'\n';
	}
	return 0;
} 
