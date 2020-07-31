/*

Consider a directed graph whose vertices are numbered from 1 to n. There is an 
edge from a vertex i to a vertex j iff either j = i + 1 or j = 3i. The task is to 
find the minimum number of edges in a path in G from vertex 1 to vertex n.

Input:
2
9
4

Output:
2
2

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
	    int count = 0;
	    while(n>1)
	    {
	        if(n%3==0)
	        {
	            n=n/3;
	            count++;
	        }
	        else
	        {
	            n=n-1;
	            count++;
	        }
	    }
	    cout << count <<'\n';
	}
	return 0;
}
