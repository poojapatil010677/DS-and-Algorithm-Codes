/*

Given an array arr[] of N non-negative integers representing height of blocks 
at index i as Ai where the width of each block is 1. Compute how much water 
can be trapped in between blocks after raining.

Example:
Input:
2
4
7 4 0 9
3
6 9 9

Output:
10
0

*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int tapwater(int* arr,int n,int* lmax, int* rmax)
{
    int water = 0;
    
    for(int i=0;i<n;i++)
    {
       /* int lmax = 0;
        int rmax = 0;
        for(int j=0;j<=i;j++)
        {
            if(arr[j]>lmax)
                lmax = arr[j];
        }
        for(int k=i;k<n;k++)
        {
            if(arr[k]>rmax)
                rmax = arr[k];
        }*/
        water+= min(lmax[i],rmax[i])-arr[i];
    }
    return water;
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
	    int lmax[n];
	    int rmax[n];
	    
	    lmax[0] = arr[0];
	    rmax[n-1] = arr[n-1];
	    
	    for(int i=1;i<n;i++)
	    { 
	        lmax[i] = max(lmax[i-1],arr[i]);
	    }
	    for(int i=n-2;i>=0;i--)
	    {
	        rmax[i] = max(rmax[i+1],arr[i]);
	    }
	    int res = tapwater(arr,n,lmax,rmax);
	    cout << res <<"\n";
	}
	return 0;
}
