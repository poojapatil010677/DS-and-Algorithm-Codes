/*

Given a point on x axis, (N,0), you are standing at origin and you can only move on x-axis. 
Lets say you are at (x,0), at each step you can either move one step forward ie (x+1,0) 
or one step backwards (x-1,0) or make a jump to double your current position (2*x,0). 
One step movement costs you A while a jump costs you B. If your initial position is (0,0) , 
find the minimum cost to reach (N,0) .

Example:
Input:
1
7 1 100

Output:
7

*/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,a,b;
	    cin>>n>>a>>b;
	    long int dp[n+1];
	    dp[0] = 0;
	    dp[1] = a;
	    for(int i=2;i<=n;i++)
	        dp[i] = min(a+dp[i-1],(i%2)*a+dp[(i+1)/2]+b);
	   cout<<dp[n]<<'\n';
	}
	return 0;
}
