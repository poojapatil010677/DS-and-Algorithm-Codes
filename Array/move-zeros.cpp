/*

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        while(k<nums.size() && nums[k]!=0)
            k++;
        if(k>=nums.size())
            return;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0 && k<i)
            {
                nums[k++] = nums[i];
                nums[i] = 0;
            }
        }
    }
};