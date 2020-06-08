/*

Container with most water

Given n non-negative integers a1, a2, ..., an , where each represents a point 
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints 
of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
forms a container, such that the container contains the most water.

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

*/

// brute force
// time complexity : O(n^2)


int maxArea(int* height, int heightSize){
    int max_area = INT_MIN;
    int min,max;
    for(int i=0;i<heightSize-1;i++)
    {
        for(int j=i+1;j<heightSize;j++)
        {
            if(height[i]<height[j])
                min = height[i];
            else
                min = height[j];
            max = (j-i)* min;
            if(max>max_area)
                max_area = max;
        }
    }
    return max_area;
}


// two pointer method
// time-complexity : O(n)

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()==0 || height.size()==1) return 0;
        int l = 0;
        int r = height.size()-1;
        int maxArea = (r-l) * min(height[r],height[l]);
        int temp = 0;
        while(l<r)
        {
            temp = (r-l) * min(height[r],height[l]);
            //cout << temp << "\n";
            if(temp>maxArea) maxArea = temp;
            if(height[r]>height[l]) l++;
            else
                r--;
        }
        return maxArea;
    }
};
