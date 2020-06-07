// coin change

/*

You are given coins of different denominations and a total amount of money. 
Write a function to compute the number of combinations that make up that 
amount. You may assume that you have infinite number of each kind of coin.

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0) return 1;
        int n = coins.size();
        int dp[n+1][amount+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(j==0) dp[i][j] = 1;
                else if(i==0) dp[i][j] = 0;
                else if(j<coins[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];   
                }
            }
        }
        return dp[n][amount];
    }
};
