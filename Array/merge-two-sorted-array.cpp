/*

Merge Two sorted array without using extra space

*/

#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int m,n;
	    scanf("%d %d",&m,&n);
	    int a1[m],a2[n];
	    for(int i=0;i<m;i++)
	    {
	        scanf("%d",&a1[i]);
	    }
	    for(int j=0;j<n;j++)
	    {
	        scanf("%d",&a2[j]);
	    }
	    int i = n-1,j = m-1;
	    while(i>=0)
	    {
	        if(a2[i]>a1[j])
	            i--;
	        else
	        {
	            int last = a1[j];
	            j--;
	            while(j>=0 && a1[j]>a2[i])
	            {
	                a1[j+1] = a1[j];
	                j--;
	            }
	            a1[j+1] = a2[i];
	            a2[i] = last;
	            i--;
	            j = m-1;
	        }
	    }
	    for(int i=0;i<m;i++)
	    {
	        cout << a1[i] <<' ';
	    }
	    for(int i=0;i<n;i++)
	    {
	        cout << a2[i] << ' ';
	    }
	    cout <<'\n';
	}
	return 0;
}
