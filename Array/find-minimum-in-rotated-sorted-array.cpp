/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0

*/

// Method 1

class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = -1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
                res = nums[i];
        }
        if(res==-1)
            return nums[0];
        return res;
    }
};

//Method 2

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int m = nums[0];
        int mid;
        int l = 0,r=nums.size()-1;
        int hold = -1;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(nums[mid]>=m)
                l = mid+1;
            else if(nums[mid]<m && nums[mid]<nums[mid-1])
            {
                hold = nums[mid];
                break;
            }
            else if(nums[mid]<m)
            {
                hold = nums[mid];
                r = mid-1;
            }
        }
        if(hold==-1)return nums[0];
        return hold;
    }
};

// different approach 

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int s = 0,e = nums.size()-1;
        while(s<e)
        {
            int mid = (s+e)/2;
            if(nums[mid]<nums[e]) 
                e = mid;
            else if(nums[mid]>nums[e])
                s = mid + 1;
        }
        return nums[e];
    }
};
