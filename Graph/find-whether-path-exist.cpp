/*

Find whether path exist

Given a N X N matrix (M) filled with 1, 0, 2, 3. The task is to find whether 
there is a path possible from source to destination, while traversing through 
blank cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there is only single source and single destination.

*/

#include <iostream>
#include<vector>
using namespace std;

bool path(vector<vector<int>>& v, int i, int j, int n)
{
    if(i<0 || j<0 || i>=n || j>=n || v[i][j]==0 || v[i][j]==-1)
        return false;
    else if(v[i][j]==2) return true;
    else
    {
        int temp = v[i][j];
        v[i][j] = -1;
        bool res = path(v,i-1,j,n) || path(v,i+1,j,n) || 
                   path(v,i,j-1,n) || path(v,i,j+1,n) ;
        v[i][j] = temp;
        return res;
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++)
        {
            vector<int> temp(n);
            for(int j=0;j<n;j++)
            {
                scanf("%d",&temp[j]);
            }
            v[i] = temp;
        }
        bool res;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==1)
                {
                    res = path(v,i,j,n);
                    break;
                }
            }
        }
        if(res) printf("%d\n",1);
        else
        printf("%d\n",0);
    }
	return 0;
} 
