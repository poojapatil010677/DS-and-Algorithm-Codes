/*

Given an integer find the factorial of the number
https://www.geeksforgeeks.org/factorial-large-number/

*/

#include <iostream>
#define MAX 3000
using namespace std;

int multiply(int n,int* res,int& res_size)
{
    int carry = 0;
    for(int i=0;i<res_size;i++)
    {
        int prod = res[i]*n + carry;
        res[i] = prod%10;
        carry = prod/10;
    }
    while(carry>0)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int res[MAX];
	    res[0] = 1;
	    int res_size = 1;
	    for(int i=2;i<=n;i++)
	    {
	        res_size = multiply(i,res,res_size);
	    }
	    for(int i=res_size-1;i>=0;i--)
	    cout<<res[i];
	    cout<<'\n';
	}
	return 0;
}

