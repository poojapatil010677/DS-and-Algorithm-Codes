/*
3sum

Given an array nums of n integers, are there elements a, b, c in nums such 
that a + b + c = 0? Find all unique triplets in the array which gives the sum 
of zero.

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n<3) return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            int l = i+1;
            int r = n-1;
            if(i>0 && nums[i]==nums[i-1])
                continue;
            while(l<r)
            {
                if(nums[i]+nums[l]+nums[r]==0)
                {
                    vector<int> temp{nums[i],nums[l],nums[r]};
                    res.push_back(temp);
                
                    r--;
                    l++;
                    while(l<r && nums[r]==nums[r+1]) r--;
                    while(l<r && nums[l]==nums[l-1]) l++;
                }
                else if(nums[l]+nums[r]>-nums[i])
                    r--;
                else
                    l++;
            }
        }
        return res;
    }
};

// Time complexity : O(n^2)
