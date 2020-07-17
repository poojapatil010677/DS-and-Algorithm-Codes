/*

Convert to reduced form

Given an array with n distinct elements, convert the given array to a reduced 
form where all elements are in range from 0 to n-1. The order of elements 
is same, i.e., 0 is placed in place of smallest element, 1 is placed for second 
smallest element, … n-1 is placed for largest element.

Input:
2
3
10 40 20
5
5 10 40 30 20

Output:
0 2 1
0 1 4 3 2

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    int a[n],b[n];
	    for(int i=0;i<n;i++)
	    {
	        cin >> a[i];
	        b[i] = a[i];
	    }
	    
	    sort(a,a+n);
	    int h[1001];
	    for(int i=0;i<n;i++)
	    {
	        h[a[i]] = i;
	    }
	    for(int i=0;i<n;i++)
	    {
	        cout << h[b[i]]<<' ';
	    }
	    cout <<'\n';
	    
	}
	return 0;
}
