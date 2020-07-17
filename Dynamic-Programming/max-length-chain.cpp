/*

Max length chain

You are given N pairs of numbers. In every pair, the first number is always smaller 
than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain 
of pairs can be formed in this fashion. Your task is to complete the function maxChainLen 
which returns an integer denoting the longest chain which can be formed from a 
given set of pairs. 

Input
2
5
5  24 39 60 15 28 27 40 50 90
2
5 10 1 11 
Output
3
1

*/

bool cmp(const val& a, const val& b)
{
    return b.second>a.second;
}

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
    if(n==0) return 0;
    sort(p,p+n,cmp);
    int dp[n];
    dp[0] = 1;
    for(int i=1;i<n;i++)
    {
        dp[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(p[i].first>p[j].second)
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    int res = 0;
    for(int i=0;i<n;i++)
    {
        res = max(res,dp[i]);
    }
    return res;
}
