/*

Print first n Fibonacci Numbers

Given a number N, print the first N fibonacci numbers.

*/

void printFibb(int n) {
    //code here
    long long int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    for(int i=1;i<=n;i++)
    {
        cout << dp[i] <<" ";
    }
}
