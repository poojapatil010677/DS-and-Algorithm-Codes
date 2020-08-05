/*

Given a string you need to print the size of the longest possible substring that has exactly k unique characters. If there is no possible substring print -1.
Example
For the string aabacbebebe and k = 3 the substring will be cbebebe with length 7.
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
	    int k;
	    cin>>k;
	    int hold[26] = {0};
	    int maxlen = INT_MIN;
	   for(int i=0;i<s.length();i++)
	   {
	       memset(hold,0,sizeof(hold));
	       int temp = 0;
	       for(int j=i;j<s.length();j++)
	       {
	           hold[s[j]-'a']++;
	           if(hold[s[j]-'a']==1)
	                temp++;
	           if(temp==k)
	           {
	               maxlen = max(j-i+1,maxlen);
	           }
	           if(temp>k)break;
	       }
	   }
	   if(maxlen==INT_MIN)cout<<-1<<'\n';
	   else
	   cout<<maxlen<<'\n';
	}
	return 0;
}
