/*

Given a string, find the length of the longest substring without repeating characters. For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6.

*/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int visit[26]={0};
	    int start=0,maxlen=0;
	    int i;
	    for(i=0;i<s.length();i++)
	    {
	        if(visit[s[i]-'a']==1)
	        {
	            maxlen = max(maxlen,i-start);
	            while(s[start]!=s[i])
	            {
	                visit[s[start]-'a']=0;
	                start++;
	            }
	            start++;
	        }
	        else
	        {
	            visit[s[i]-'a'] = 1;
	        }
	    }
	    maxlen = max(maxlen,i-start);
	    cout<<maxlen<<'\n';
	}
	return 0;
}


