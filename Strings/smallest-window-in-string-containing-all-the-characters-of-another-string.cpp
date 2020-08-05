/*

Given a string S and text T. Output the smallest window in the string S having all characters of the text T. Both the string S and text T contains lowercase english alphabets.

Input:
2
timetopractice
toc
zoomlazapzo
oza

Output:
toprac
apzo

*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s1,s2;
	    cin>>s1>>s2;
	    int n1 = s1.length();
	    int n2 = s2.length();
	    
	    int hash_pat[256] = {0};
	    int hash_str[256] = {0};
	    
	    for(int i=0;i<n2;i++)
	        hash_pat[s2[i]]++;
	        
	    int start=0,start_index=-1,min_len=INT_MAX;
	    int count=0;
	    for(int j=0;j<n1;j++)
	    {
	        hash_str[s1[j]]++;
	        if(hash_pat[s1[j]]!=0 && hash_str[s1[j]]<=hash_pat[s1[j]])
	            count++;
	       
	        if(count==n2)
	        {
	            while(hash_str[s1[start]]>hash_pat[s1[start]] || hash_pat[s1[start]]==0)
	            {
	                if(hash_str[s1[start]]>hash_pat[s1[start]])
	                    hash_str[s1[start]]--;
	               start++;
	            }
	            
	            int len = j-start+1;
	            if(min_len>len)
	            {
	                min_len = len;
	                start_index = start;
	            }
	        }
	    }
	    
	    cout<<s1.substr(start_index,min_len)<<'\n';
	}
	return 0;
}
