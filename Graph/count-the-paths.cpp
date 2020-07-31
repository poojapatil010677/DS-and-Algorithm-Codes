/*

Count the paths

Given a directed graph, a source vertex ‘s’ and a destination vertex ‘d’, print 
the count of all paths from given ‘s’ to ‘d’.

Example:
Input:
1
4 6
0 1 0 2 0 3 2 0 2 1 1 3
2 3
Output:
3

*/

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

void dfs(vector<int> v[],int i,int* hold,int d,int* count)
{
    if(i==d)
    {
        *count = *count+1;
        return;
    }
    else if(hold[i]==0)
    {
        hold[i] = 1;
        for(int k=0;k<v[i].size();k++)
        {
            dfs(v,v[i][k],hold,d,count);
        }
        hold[i] = 0;
    }
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,e;
	    scanf("%d %d",&n,&e);
	    int arr[e*2];
	    for(int i=0;i<(2*e);i++)
	    {
	        scanf("%d",&arr[i]);
	    }
	    int s,d;
	    scanf("%d %d",&s,&d);
	    if(s==d)
	        cout << 1 <<'\n';
	   else
	   {
    	    vector<int> v[n];
    	    for(int i=0;i<(2*e);i+=2)
    	    {
    	        v[arr[i]].push_back(arr[i+1]);
    	    }
    	    int count = 0;
    	    int hold[n];
    	    memset(hold,0,sizeof(int)*n);
    	    hold[s] = 1;
    	    for(int i=0;i<v[s].size();i++)
    	    {
    	        dfs(v,v[s][i],hold,d,&count);
    	    }
    	    cout << count << '\n';
	   }
	}
	return 0;
}
