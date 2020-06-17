/*

Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Expected Time Complexity : O(N*N)
Expected Auxiliary Space: O(N*N)

Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC
Output:
3
2
*/

int lcs(int x, int y, string s1, string s2){
    
    // your code here
    if(x==0 || y==0) return 0;
    
    int dp[x+1][y+1];
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    return dp[x][y];
    
}

