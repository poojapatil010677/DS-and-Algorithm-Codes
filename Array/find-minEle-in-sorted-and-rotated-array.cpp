/*

Minimum element in a sorted and rotated array

A sorted array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

Expected Time Complexity: O(Log n)

*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int findMin(int* arr, int l, int r)
{
    int mid  = (l+r)/2;
    if(l==r) return arr[l];
    else if(l==mid) return min(arr[l],arr[r]);
    else if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1])
        return arr[mid];
    else
    {
        int lv = findMin(arr,l,mid-1);
        int rv = findMin(arr,mid+1,r);
        return min(lv,rv);
    }
}

int main() {
	int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        int res = findMin(arr,0,n-1);
        cout << res << '\n';
    }
	return 0;
}
