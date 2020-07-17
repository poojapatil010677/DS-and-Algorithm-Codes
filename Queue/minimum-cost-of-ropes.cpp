/*

Minimum cost of ropes

There are given N ropes of different lengths, we need to connect these ropes into 
one rope. The cost to connect two ropes is equal to sum of their lengths. The task is 
to connect the ropes with minimum cost.

Input:
2
4
4 3 2 6
5
4 2 7 6 9

Output:
29
62

*/

#include <iostream>
#include <queue>
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
	    priority_queue<long long,vector<int>,greater<int>> pq;
	    for(int i=0;i<n;i++)
	    {
	        pq.push(arr[i]);
	    }
	    long long cost = 0;
	    while(true)
	    {
	        int v1 = pq.top();
	        pq.pop();
	        if(pq.empty())
	        {
	            break;
	        }
	        int v2 = pq.top();
	        pq.pop();
	        cost +=v1+v2;
	        pq.push(v1+v2);
	    }
	    cout << cost << '\n';
	}
	return 0;
}
