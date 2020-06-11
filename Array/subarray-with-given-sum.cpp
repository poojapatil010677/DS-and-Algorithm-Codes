/*

Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Example:
Input:
3
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10
4 15
5 7 1 2
Output:
2 4
1 5
1 4

*/


// Flexible sliding window approach

// Function to find the subarray with given sum k
// arr: input array
// n: size of array
void subarraySum(int arr[], int n, int s){
    
    // Your code here
    int sum = 0;
    int i = 0;
    int j = 0;
    while(j<=n)
    {
        if(sum==s)
        {
            printf("%d %d",i+1,j);
            break;
        }
        else
        {
            if(sum>s)
            {
                sum = sum - arr[i];
                i++;
            }
            else
            {
                sum = sum + arr[j];
                j++;
            }
        }
        
    }
    if(j>n)
    printf("%d",-1);
    
}
