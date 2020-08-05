/*
Implement the next permutation, which rearranges numbers into the numerically next greater 
permutation of numbers. If such arrangement is not possible, it must be rearranged as the 
lowest possible order ie, sorted in an ascending order.

For example:
1,2,3 → 1,3,2
3,2,1 → 1,2,3

Input:
1
6
1 2 3 6 5 4

Output:
1 2 4 3 5 6

*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    int i;
	    for(i=n-1;i>=0;i--)
	    {
	        if(arr[i-1]<arr[i])
	            break;
	    }
	    int x = arr[i-1];
	    int small = i;
	    for(int j=i+1;j<n;j++)
	    {
	        if(arr[j]>x && arr[j]<arr[small])
	            small = j;
	    }
	    swap(arr[i-1],arr[small]);
	    sort(arr+i,arr+n);
	    for(int i=0;i<n;i++)
	    {
	        cout<<arr[i]<<' ';
	    }
	    cout<<'\n';
	}
	return 0;
}
