/*

First non-repeating character in a stream

Given an input stream of N characters consisting only of lower case alphabets.
The task is to find the first non repeating character, each time a character 
is inserted to the stream. If no non repeating element is found print -1.

Input:
2
4
a a b c
3
a a c

Output:
a -1 b b
a -1 c

*/

#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    vector<char> str(n);
	    for(int i=0;i<n;i++)
	        cin>>str[i];
	      
	   unordered_map<char,int> mp;
	   queue<char> q;
	   for(int i=0;i<n;i++)
	   {
	       if(mp.find(str[i])==mp.end())
	       {
	           q.push(str[i]);
	       }
	       mp[str[i]]++;
	       if(mp[q.front()]==1)
	       {
	           cout<<q.front()<<' ';
	       }
	       else
	       {
                while(1)
                {
                    if(q.empty())
                    {
                    cout<< -1 <<' ';
                    break;
                    }
                    
                    else
                    {
                        if(mp[q.front()]>1)
                        q.pop();
                        
                        else
                        {
                            cout<< q.front() <<' ';
                            break;
                        }
                    }
                }
	       }
	       
	   }
	   printf("\n");
	   
	}
	return 0;
}

