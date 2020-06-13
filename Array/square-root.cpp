/*
Given an integer x. The task is to find the square root of x. If x is not a perfect square, then return floor(√x).

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Input:
2
5
4
Output:
2
2

*/

// Binary search approach


// Function to find square root
// x: element to find square root
long long int floorSqrt(long long int x) 
{
    // Your code goes here   
    if(x==0 || x==1)return x;
    long long int l = 1;
    long long int r = x;
    long long int mid,ans;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(mid*mid==x) return mid;
        else if(mid*mid>x)
        {
           // ans = mid;
            r = mid-1;
        }
        else
        {
            ans = mid;
            l = mid+1;
        }
    }
    return ans;
}

