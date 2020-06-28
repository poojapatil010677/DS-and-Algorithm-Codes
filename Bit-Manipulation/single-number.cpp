/*

Single Number

Given a non-empty array of integers, every element appears twice except 
for one. Find that single one.

*/

int singleNumber(vector<int>& nums) {
        
        int res = 0;
        for(int i=0;i<nums.size();i++)
        {
            res = res^nums[i];
        }
        
        return res;
}

