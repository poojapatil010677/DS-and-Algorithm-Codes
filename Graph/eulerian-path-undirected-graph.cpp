/*

Given an adjacency matrix representation of an unweighted undirected graph, your 
task is to complete the function eulerianPath(), that returns true if there is a 
Eulerian Path in the graph.

Input:
2
5
0 1 0 1 1
1 0 1 0 1
0 1 0 1 1
1 1 1 0 0
1 0 1 0 0
5
0 1 0 0 1
1 0 1 1 1
0 1 0 1 0
0 1 1 0 1
1 1 0 1 0
Output:
0
1

*/

#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    int arr[n][n];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            scanf("%d",&arr[i][j]);
	        }
	    }
	    int count = 0;
	    for(int i=0;i<n;i++)
	    {
	        int temp = 0;
	        for(int j=0;j<n;j++)
	        {
	            if(arr[i][j]==1)
	                temp++;
	        }
	        if(temp%2!=0)
	            count++;
	    }
	    if(count==0 || count==2)
	        cout << 1 <<'\n';
	    else
	        cout << 0 << '\n';
	}
	return 0;
}
