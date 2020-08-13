/*

Given a sorted array of integers A(0 based index) of size N, find the starting and ending position of a given integar B in array A.

Your algorithm’s runtime complexity must be in the order of O(log n).

Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].

Input 1:
    A = [5, 7, 7, 8, 8, 10]
    B = 8
Output 1:
    [3, 4]
Explanation 1:
    First occurence of 8 in A is at index 3
    Second occurence of 8 in A is at index 4
    ans = [3, 4]

Input 2:
    A = [5, 17, 100, 111]
    B = 3
Output 2:
    [-1, -1]
*/

int binarylow(const vector<int> &A,int B,int l,int r)
{   
    while(l<=r)
    {
        int mid = (l+r)/2;
        if((mid==0 || A[mid-1]<B) && A[mid]==B)
            return mid;
        else if(A[mid]>=B)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int binaryhigh(const vector<int> &A,int B,int l,int r)
{
    while(l<=r)
    {
        int mid = (l+r)/2;
        if((mid==r || A[mid+1]>B) && A[mid]==B)
            return mid;
        else if(A[mid]<=B)
            l = mid + 1;
        else if(A[mid]>B)
            r = mid - 1;
    }
    return -1;    
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n = A.size();
    vector<int> res(2);
    res[0] = binarylow(A,B,0,n-1);
    res[1] = binaryhigh(A,B,0,n-1);
    return res;
}

