
/*

Maximum Rectangular Area in a Histogram

Find the largest rectangular area possible in a given histogram where the largest 
rectangle can be made of a number of contiguous bars. For simplicity, assume that 
all bars have same width and the width is 1 unit.

Example:
Input: 
2
7
6 2 5 4 5 1 6
4
6 3 4 2
Output:
12
9

*/

#include <iostream>
#include<stack>
#include<bits/stdc++.h>
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
	    
	    stack<long long int> s;
	    int i = 0;
	    long long int curr_area=0,max_area=0,tp;
	    while(i<n)
	    {
	        if(s.empty() || arr[s.top()]<=arr[i])
	            s.push(i++);
	            
	        else
	        {
	            tp = s.top();
	            s.pop();
	            
	            curr_area = arr[tp] * (s.empty()?i:i-s.top()-1);
	            max_area = max(max_area,curr_area);
	        }
	    }
	    while(!s.empty())
	    {
	        tp = s.top();
	        s.pop();
	            
	        curr_area = arr[tp] * (s.empty()?i:i-s.top()-1);
	        max_area = max(max_area,curr_area);
	    }
	    cout << max_area <<'\n';
	}
	return 0;
}
