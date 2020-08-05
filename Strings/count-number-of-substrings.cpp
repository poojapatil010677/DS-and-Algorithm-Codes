/*

Count number of substrings

Given a string of lowercase alphabets, count all possible substrings (not necessarily 
distinct) that have exactly k distinct characters.

Example:

Input
1
aba
2

Output
3

*/

#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int k;
	    cin>>k;
	    int count = 0;
	    int cnt[26];
	    for(int i=0;i<s.length();i++)
	    {
	        int dist = 0;
	        memset(cnt,0,sizeof(cnt));
	        for(int j=i;j<s.length();j++)
	        {
	            cnt[s[j]-'a']++;
	            if(cnt[s[j]-'a']==1)
	                dist++;
	            if(dist==k)
	                count++;
	            if(dist>k)
	                break;
	        }
	    }
	    cout<<count<<'\n';
	}
	return 0;
}
