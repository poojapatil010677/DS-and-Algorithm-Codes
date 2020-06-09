/* 

Remove Duplicates from sorted array

Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1) return n;
        int i = 0;
        int j = 1;
        int count = 1;
        while(j<n)
        {
            if(nums[j]!=nums[j-1])
            {
                i+=1;
                nums[i] = nums[j];
                count++;
            }
            j++;
        }
        return count;
    }
};
