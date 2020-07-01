/*

Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

ref: https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
 
Time Complexity : O(n*n)
Space Complexity : O(n*n)

*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==0 || n==1) return s;
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            dp[i][i] = 1;
        }
        int maxlen = 1;
        int start = 0;
        for(int l=2;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                int j = i+l-1;
                if(s[i]==s[j] && l==2)
                {
                    dp[i][j]=1;
                    start = i;
                    maxlen=2;
                }
                else if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j]=1;
                    if(l>maxlen)
                    {
                        start = i;
                        maxlen = l;
                    }
                }
                else
                    dp[i][j] = 0;
            }
        }
        return s.substr(start,maxlen);
    }
};

