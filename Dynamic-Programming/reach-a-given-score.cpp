/*

Reach a given score

Consider a game where a player can score 3 or 5 or 10 points in a move. Given a 
total score n, find the number of distinct combinations to reach the given score.


Input:
3
8
20
13

Output:
1
4
2

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
	   for(int i=0;i<=n;i++)
	        dp[i] = 0;
	   dp[0] = 1;
	   for(int i=3;i<=n;i++)
	        dp[i] += dp[i-3];
	        
	   for(int i=5;i<=n;i++)
	        dp[i] += dp[i-5];
	       
	   for(int i=10;i<=n;i++)
	        dp[i] += dp[i-10];
	        
	   cout<<dp[n]<<'\n';
	}
	return 0;
}
