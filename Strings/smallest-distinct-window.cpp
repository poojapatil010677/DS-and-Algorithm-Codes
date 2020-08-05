/*

Smallest distinct window

Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.

Input:
2
aabcbcdbca
aaab

Output:
4
2

*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int visited[256] = {0};
	    int unique = 0;
	    for(int i=0;i<s.length();i++)
	    {
	        if(visited[s[i]]==0)
	       {
	           visited[s[i]] = 1;
	           unique++;
	       }
	    }
	   // cout<<unique<<' ';
	    int hash[256] = {0};
	    int maxlen = INT_MAX;
	    int start = 0;
	    int count=0;
	    for(int i=0;i<s.length();i++)
	    {
	        hash[s[i]]++;
	        if(hash[s[i]]==1)
	            count++;
	        if(count==unique)
	        {
	            while(hash[s[start]]>1)
	            {
	                hash[s[start]]--;
	                start++;
	            }
	            int l = i-start+1;
	         //   cout<<l<<' ';
	            if(maxlen>l)
	            {
	                maxlen = l;
	            }
	        }
	    }
	    cout<<maxlen<<'\n';
	}
	return 0;
}
