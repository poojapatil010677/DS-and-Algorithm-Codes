/*

Minimum size subarray sum

Given an array of n positive integers and a positive integer s, find the 
minimal length of a contiguous subarray of which the sum ≥ s. If there isn't 
one, return 0 instead.
Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem 
constraint.

*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int total = 0;
        int res = INT_MAX;
        int j=0;
        int i=0;
        while(j<n)
        {
            total = total + nums[j];
            while(total>=s)
            {
                res = min(res,j-i+1);
                total = total - nums[i];
                i = i+1;
            }
            j = j+1;
        }
        if(res==INT_MAX) return 0;
        return res;
    }
};

//time complexity : O(n) - two pointer method
