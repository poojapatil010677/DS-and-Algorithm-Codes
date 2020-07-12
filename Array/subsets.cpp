/*

Subsets

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

class Solution {
public:
    
    void addsets(vector<int>& nums,vector<vector<int>>& res,vector<int> temp,int i)
    {
        if(i==nums.size())
        {
            res.push_back(temp);
            return;
        }
        else
        {
            addsets(nums,res,temp,i+1);
            temp.push_back(nums[i]);
            addsets(nums,res,temp,i+1);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        addsets(nums,res,temp,0);
        return res;
    }
};
