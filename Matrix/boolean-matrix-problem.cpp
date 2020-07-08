/*

Boolean Matrix Problem

Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix 
cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column
as 1.

time-complexity : O(m*n)
space-complexity : O(1)

*/

#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int m,n;
	    scanf("%d %d",&m,&n);
	    vector<vector<int>> v(m);
	    for(int i=0;i<m;i++)
	    {
	        vector<int> temp(n);
	        for(int j=0;j<n;j++)
	        {
	            scanf("%d",&temp[j]);
	        }
	        v[i] = temp;
	    }
	    
	    bool rf,cf;
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(i==0 && v[i][j]==1)
	                rf = true;
	            if(j==0 && v[i][j]==1)
	                cf = true;
	             if(v[i][j]==1)
	             {
	                 v[0][j] = 1;
	                 v[i][0] = 1;
	             }
	        }
	    }
	    
	    for(int i=1;i<m;i++)
	    {
	        for(int j=1;j<n;j++)
	        {
	            if(v[i][0]==1 || v[0][j]==1)
	                v[i][j] = 1;
	        }
	    }
	    
	    if(cf)
	    {
	        for(int i=0;i<m;i++)
	            v[i][0] = 1;
	    }
	    
	    if(rf)
	    {
	        for(int i=0;i<n;i++)
	            v[0][i] = 1;
	    }
	    
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            printf("%d ",v[i][j]);
	        }
	        printf("\n");
	    }
	    
	}
	return 0;
}
