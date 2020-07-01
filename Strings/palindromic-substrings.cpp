/*

Palindromic Substrings

Given a string, your task is to count how many palindromic substrings in 
this string.

The substrings with different start indexes or end indexes are counted as 
different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Time complexity :

Brute force : O(n^3)
Dynamic Programming : O(n^2)

*/

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();
        if(n==0 || n==1) return n;
        
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            dp[i][i] = 1;
            count++;
        }
        
        for(int l=2;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                int j = i+l-1;
                if(s[i]==s[j] && l==2)
                {
                    dp[i][j] = 1;
                    count++;
                }
                else if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = 1;
                    count++;
                }
                else
                    dp[i][j] = 0;
            }
        }
        
        return count;
    }
};
