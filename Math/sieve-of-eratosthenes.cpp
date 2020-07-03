/*

Given a number N, calculate the prime numbers upto N using Sieve of Eratosthenes. 

Time complexity : O(n(loglogn))

*/

#include <iostream>
#include<string.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    
	    bool arr[n+1];
	    memset(arr,true,sizeof(arr));
	    
	    for(int i=2;i*i<=n;i++)
	    {
	        if(arr[i]==true)
	        {
	            for(int j=i*i;j<=n;j+=i)
	            {
	                arr[j]=false;
	            }
	        }
	    }
	    
	    for(int i=2;i<=n;i++)
	    {
	        if(arr[i])
	            cout << i <<' ';
	    }
	    cout <<'\n';
	}
	return 0;
}
