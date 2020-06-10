/*

https://www.geeksforgeeks.org/counting-inversions/

Given an array of positive integers. The task is to find inversion count of array.

Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Method 1 : using two loops - O(n^2) solution
Method 2 : using merge sort concept - O(nlogn) solution

*/

#include <stdio.h>
#include <stdlib.h>

int merge(int* arr, int* temp, int l, int mid, int r)
{
    int i,j,k;
    long int invc = 0;
    i = l;
    j = mid+1;
    k = 0;
    while(i<=mid && j<=r)
    {
        if(arr[i]<arr[j])
        {
            temp[k++] = arr[i++];
        }
        if(arr[i]>arr[j])
        {
            temp[k++] = arr[j++];
            invc = invc + (mid-i+1);
        }
    }
    while(i<=mid)
    {
        temp[k++] = arr[i++];
    }
    while(j<=r)
    {
        temp[k++] = arr[j++];
    }
    i=l;
    k=0;
    while(i<=r)
    {
        arr[i++] = temp[k++];
    }
    
    return invc;
}

int _mergesort(int* arr, int* temp, int l, int r)
{
    long int invC = 0;
    int mid;
    if(l<r)
    {
        mid = (l+r)/2;
        invC += _mergesort(arr,temp,l,mid);
        invC += _mergesort(arr,temp,mid+1,r);
        invC += merge(arr,temp,l,mid,r);
    }
    return invC;
}

int mergeSort(int* arr, int n)
{
    int* temp = (int*)malloc(sizeof(int)*n);
    return _mergesort(arr,temp,0,n-1);
}

int main() {
	//code
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    int arr[n];
	    for(int i=0; i<n;i++)
	    {
	        scanf("%d",&arr[i]);
	    }
	    int res = mergeSort(arr,n);
	    printf("%d\n",res);
	}
	return 0;
}


