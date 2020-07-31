/*

Josephus problem

Given the total number of persons n and a number k which indicates that k-1 persons 
are skipped and kth person is killed in circle in a fixed direction.​The task is to 
choose the safe place in the circle so that when you perform these operations starting 
from 1st place in the circle, you are the last one remaining and survive.

Input:
2
3 2
5 3
Output:
3
4

*/

int josephus(int n, int k)
{
    if(n==1)
        return 1;
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++)
    {
        dp[i] = (dp[i-1]+k-1)%i+1;
    }
    return dp[n];
}


