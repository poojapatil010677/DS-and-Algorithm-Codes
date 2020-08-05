#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void powerset(string s,int n,int index,string t="")
{
    if(n==index)
    {
        return;
    }
    else
    {
        cout<<t<<'\n';
        for(int i=index+1;i<n;i++)
        {
            t = t+s[i];
            powerset(s,n,i,t);
            t = t.erase(t.length()-1);
        }
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    sort(s.begin(),s.end());
	    int n = s.length();
	    powerset(s,n,-1);
	}
	return 0;
}
