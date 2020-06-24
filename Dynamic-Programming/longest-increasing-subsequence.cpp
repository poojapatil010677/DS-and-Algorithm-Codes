/*

Longest Increasing Subsequence

Given a sequence A of size N, find the length of the longest increasing 
subsequence from a given sequence .The longest increasing subsequence means to 
find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as 
long as possible. This subsequence is not necessarily contiguous, or unique.

Note: Duplicate numbers are not counted as increasing subsequence.

Input:
2
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6
5 8 3 7 9 1

Output:
6
3

*/

#include <iostream>
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
	    
	    int dp[n];
	    dp[0] = 1;
	    for(int i=1;i<n;i++)
	    {
	        dp[i] = 1;
	        for(int j=0;j<i;j++)
	        {
	            if(arr[j]<arr[i] && dp[i]<(dp[j]+1))
	                dp[i] = dp[j] + 1;
	        }
	    }
	    int maxm = 0;
	    for(int i=0;i<n;i++)
	    {
	        maxm = max(maxm,dp[i]);
	    }
	    cout << maxm << "\n";
	}
	return 0;
}
