/*

Convert Binary to decimal

*/


#include <stdio.h>

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    long long int n;
	    scanf("%ld",&n);
	    int deci = 0;
	    int i = 1;
	    while(n)
	    {
	      
	        if(n%10==1)
	            deci+=i;
	        i = i * 2;
	        n = n/10;
	    }
	    printf("%d\n",deci);
	}
	return 0;
}
