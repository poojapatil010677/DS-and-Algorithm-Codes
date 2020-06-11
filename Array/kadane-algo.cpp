/*

Max sum subarray

Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Example:
Input:
2
5
1 2 3 -2 5
4
-1 -2 -3 -4

Output:
9
-1
*/

/ Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for(int i=0;i<n;i++)
    {
        max_ending_here +=arr[i];
        if(max_ending_here < arr[i])
            max_ending_here = arr[i];
        if(max_so_far<max_ending_here)
            max_so_far = max_ending_here;
    }
    
    return max_so_far;
}
