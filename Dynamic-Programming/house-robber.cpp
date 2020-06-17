/*

House Robber

Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

Input:
2
6
5 5 10 100 10 5
3
1 2 3
Output:
110
4

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        int cost[n+1];
        cost[0] = 0;
        cost[1] = nums[0];
        for(int i=2;i<=n;i++)
        {
            cost[i] = max(cost[i-2]+nums[i-1],cost[i-1]);
        }
        return cost[n];
    }
};

