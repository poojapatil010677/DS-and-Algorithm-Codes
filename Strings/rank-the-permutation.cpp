/*

Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
Return 0 if the characters are repeated in the string.

For example:

Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba

The answer might not fit in an integer, so return your answer % 1000003

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}

int findsmall(string s,int l,int r)
{
    int count = 0;
    for(int i=l+1;i<=r;i++)
    {
        if(s[i]<s[l])
            count++;
    }
    return count;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int n = s.length();
	    int visit[26] = {0};
	    int flag=0;
	    for(int i=0;i<n;i++)
	    {
	        if(visit[s[i]-'a']==1)
	        {
	            flag = 1;
	            break;
	        }
	        else
	        visit[s[i]-'a'] = 1;
	    }
	    if(flag) cout<<0<<'\n';
	    else
	    {
	    int mul = fact(n);
	    int rank = 1;
	    int count;
	    for(int i=0;i<n;i++)
	    {
	        mul /= (n-i);
	        count = findsmall(s,i,n-1);
	        rank = rank + (count*mul);
	    }
	    cout << (rank)%1000003<<'\n';
	    }
	}
	return 0;
}
