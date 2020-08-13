/*
Given a sorted array of integers, find the number of occurrences of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return 0

**Example : **
Given [5, 7, 7, 8, 8, 10] and target value 8,
return 2.

*/

void binarysearch(const vector<int> &A,int l,int r, int B,int &count)
{
    if(l<=r)
    {
        int mid = (l+r)/2;
        if(A[mid]==B)
        {
            count = count + 1;
            if(mid-1>=l && A[mid-1]==B)
                binarysearch(A,l,mid-1,B,count);
            if(mid+1<=r && A[mid+1]==B)
                binarysearch(A,mid+1,r,B,count);
        }
        else if(A[mid]>B)
            binarysearch(A,l,mid-1,B,count);
        else
            binarysearch(A,mid+1,r,B,count);
    }
}

int Solution::findCount(const vector<int> &A, int B) {
    int n = A.size();
    int count = 0;
    binarysearch(A,0,n-1,B,count);
    return count;
}

