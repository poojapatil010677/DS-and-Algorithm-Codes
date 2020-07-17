/*

Two player X and Y are playing a game in which there are pots of gold arranged
in a  line, each containing some gold coins. They get alternating turns in which 
the player can pick a pot from one of the ends of the line. The winner is the player 
who has a higher number of coins at the end. The objective is to maximize the number 
of coins collected by X, assuming Y also plays optimally. You are required to complete 
the method maxCoins which returns an integer denoting the max coins X could get 
while playing the game. You may assume that X starts the game. 

Input:
2
4
8 15 3 7
4
2 2 2 2

Output:
22
4

time complexity : O(n*n)

*/

int maxCoins(int A[],int n)
{
   int dp[n][n];
   for(int gap=0;gap<n;gap++)
   {
       for(int i=0,j=gap;j<n;j++,i++)
       {
           int x = ((i+2)<=j)?dp[i+2][j]:0;
           int y = ((i+1)<=(j-1))?dp[i+1][j-1]:0;
           int z = (i<=(j-2))?dp[i][j-2]:0;
           
           dp[i][j] = max(A[i]+min(x,y),A[j]+min(y,z));
       }
   }
   return dp[0][n-1];
}
