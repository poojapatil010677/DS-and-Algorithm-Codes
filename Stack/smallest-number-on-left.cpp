/*

Smallest number on left

Given an array of integers, find the nearest smaller number for every element 
such that the smaller element is on left side.If no small element present on 
the left print -1.

Input:

2
3
1 6 2
6
1 5 0 3 4 5

Output:

-1 1 1
-1 1 -1 0 3 4

*/

#include <iostream>
#include <stack>
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
	    stack<int> s;
	    cout << -1 <<' ';
	    s.push(arr[0]);
	    for(int i=1;i<n;i++)
	    {
	        while(!s.empty() && s.top()>=arr[i])
	            s.pop();
	       if(s.empty())
	       {
	           cout << -1 <<' ';
	           s.push(arr[i]);
	       }
	       else
	       {
	           cout << s.top()<<' ';
	           s.push(arr[i]);
	       }
	    }
	    cout << '\n';
	}
	return 0;
}
