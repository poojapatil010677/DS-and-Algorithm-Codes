/*

Zero sum subarray

You are given an array of integers. You need to print the total count of 
sub-arrays having their sum equal to 0

Example:
Input:
2
6
0 0 5 5 0 0
10
6  -1 -3 4 -2 2 4 6 -12 -7
Output:
6
4

*/

#include <iostream>
#include<unordered_map>
using namespace std;

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
	    int sum = 0,count=0;
	    unordered_map<int,int> m;
	    for(int i=0;i<n;i++)
	    {  
	        sum = sum + arr[i];
	        if(sum==0)count++;
	        if(m.find(sum)!=m.end())
	        {
	            count += m[sum];
	            m[sum]+=1;
	        }
	        else
	        {
	            m[sum]=1;
	        }
	    }
	    printf("%d\n",count);
	}
	return 0;
}
