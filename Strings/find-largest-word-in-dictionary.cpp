/*

Find largest word in dictionary

Giving a dictionary and a string ‘str’, your task is to find the longest string in 
dictionary of size x which can be formed by deleting some characters of the given ‘str’.

Input:
2
4
ale apple monkey plea
abpcplea
4
pintu geeksfor geeksgeeks forgeek
geeksforgeeks
Output:
apple
geeksgeeks

*/

#include <iostream>
#include<vector>
using namespace std;

bool issubsequence(string a,string b)
{
    int i=0,j=0;
    while(i<a.length() && j<b.length())
    {
        if(a[i]==b[j])
        {
            j++;
            i++;
        }
        else
        {
            j++;
        }
    }
    if(i==a.length()) return true;
    return false;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<string> s(n);
	    for(int i=0;i<n;i++)
	    {
	        string temp;
	        cin>>temp;
	        s[i] = temp;
	    }
	    string p;
	    cin>>p;
	    string res;
	    int len = 0;
	    for(int i=0;i<n;i++)
	    {
	        if(len<s[i].length() && issubsequence(s[i],p))
	        {
	            len = s[i].length();
	            res = s[i];
	        }
	    }
	    cout<<res<<'\n';
	}
	return 0;
}
