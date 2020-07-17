/*

Count of subarrays

Given an array of N positive integers  a1, a2 ............ an. The value of each 
contiguous subarray of given array is the maximum element present in that subarray. 
The task is to return the number of subarrays having value strictly greater than K.

Input:
2
3 2
3 2 1
4 1
1 2 3 4

Output:
3
9

*/

#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,k;
	    scanf("%d %d",&n,&k);
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&arr[i]);
	    }
	    int sum = 0;
	    int count = 0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]<=k)
	        {
	            count++;
	        }
	        else
	        {
	            sum+=(count*(count+1)/2);
	            count = 0;
	        }
	    }
	    sum+=(count*(count+1)/2);
	    int total = n*(n+1)/2;
	    cout << total-sum <<'\n';
	    
	}
	return 0;
}
