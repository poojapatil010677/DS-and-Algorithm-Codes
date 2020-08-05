/*

N meetings in one room

There is one meeting room in a firm. There are N meetings in the form of 
(S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.

What is the maximum number of meetings that can be accommodated in the meeting room?

Input:
2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252  

Output:
1 2 4 5
6 7 1

*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Meeting
{
    int start;
    int end;
    int index;
};

bool cmp(const Meeting& a,const Meeting& b)
{
    return a.end<b.end;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Meeting arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i].start;
	        arr[i].index=i;
	    }
	    for(int i=0;i<n;i++)
            cin>>arr[i].end;
        sort(arr,arr+n,cmp);
        int i=0;
        cout<<arr[i].index+1<<' ';
        for(int j=1;j<n;j++)
        {
            if(arr[j].start>arr[i].end)
            {
                cout<<arr[j].index+1<<' ';
                i = j;
            }
        }
        cout<<'\n';
	}
	return 0;
}
