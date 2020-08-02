/*

A frog jumps either 1, 2 or 3 steps to go to top. In how many ways can it reach the top.

Input:
2
1
5
Output:
1
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
	    int dp[n+1];
	    if(n==1) cout<<1<<"\n";
	    else if(n==2) cout <<2<<"\n";
	    else
	    {
	    dp[0] = 1;
	    dp[1] = 1;
	    dp[2] = 2;
	    for(int i=3;i<=n;i++)
	    {
	        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	    }
	    cout<<dp[n]<<'\n';
	    }
	}
	return 0;
}
