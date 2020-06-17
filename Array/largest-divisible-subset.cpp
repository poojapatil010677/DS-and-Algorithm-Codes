/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]

*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if(n==0) return res;
        sort(nums.begin(),nums.end());
        vector<int> count(n,1);
        vector<int> parent(n,-1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && count[i]<count[j]+1)
                {
                    count[i] = count[j]+1;
                    parent[i] = j;
                }
            }
        }
        int max_ind = 0;
        for(int i = 0;i<n;i++)
        {
            if(count[i]>count[max_ind])
                max_ind = i;
        }
        int i = max_ind;
        while(i!=-1)
        {
            res.push_back(nums[i]);
            i = parent[i];
        }
        return res;
    }
};
