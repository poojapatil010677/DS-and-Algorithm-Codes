// Matrix Chain Multiplication

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int chainmatrix(int arr[],int n)
{
    int mat[n][n];
    
    for(int i=1;i<n;i++)
        mat[i][i] = 0;
        
    int i,j,k,l,q;
    
    for(l=2;l<n;l++)
    {
        for(i=1;i<n-l+1;i++)
        {
            j = i+l-1;
            mat[i][j] = INT_MAX;
            for(k=i;k<j;k++)
            {
                q = mat[i][k] + mat[k+1][j] + arr[i-1]*arr[k]*arr[j];
                mat[i][j] = min(q,mat[i][j]);
            }
        }
    }
    return mat[1][n-1];
}

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
        int res = chainmatrix(arr,n);
        cout << res << '\n';
	}
	return 0;
}
