/*

Maximum of all subarrays of size k 

Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.

Input:
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Output:
3 3 4 5 5 5 6
10 10 10 15 15 90 90

*/

#include <iostream>
#include <deque>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	   deque<int> q(k);
	   int i;
	   for(i=0;i<k;i++)
	   {
	       while(!q.empty() && arr[i]>=arr[q.back()])
	            q.pop_back();
	       q.push_back(i);
	   }
	   for(i=k;i<n;i++)
	   {
	       cout<<arr[q.front()]<<' ';
	       while(!q.empty() && q.front()<=i-k)
                q.pop_front();
           while(!q.empty() && arr[q.back()]<=arr[i])
                q.pop_back();
            q.push_back(i);
	   }
	   cout<<arr[q.front()]<<'\n';
	    
	}
	return 0;
}
