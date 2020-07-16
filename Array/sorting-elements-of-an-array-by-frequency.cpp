/*

Sorting Elements of an Array by Frequency

Given an array A[] of integers, sort the array according to frequency of elements. 
That is elements that have higher frequency come first. If frequencies of two 
elements are same, then smaller number comes first.

Input:
2
5
5 5 4 6 4
5
9 9 9 2 5

Output:
4 4 5 5 6
9 9 9 2 5

*/

#include <iostream>
#include<unordered_map>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

bool cmp(const pair<int,pair<int,int>>& v1,const pair<int,pair<int,int>>& v2)
{
    if(v1.second.second!=v2.second.second)
        return v1.second.second>v2.second.second;
    else 
        return v1.first<v2.first;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&arr[i]);
	    }
	    unordered_map<int,pair<int,int>> m;
	    for(int i=0;i<n;i++)
	    {
	        if(m.find(arr[i])!=m.end())
	            m[arr[i]].second++;
	        else
	            m[arr[i]]=make_pair(i,1);
	    }
	    
	    vector<pair<int,pair<int,int>>> v;
	    unordered_map<int,pair<int,int>> :: iterator itr;
	    for(itr=m.begin();itr!=m.end();itr++)
	    {
	        v.push_back(make_pair(itr->first,itr->second));
	    }
	    sort(v.begin(),v.end(),cmp);
	    for(int i=0;i<v.size();i++)
	    {
	        int l = v[i].second.second;
	        while(l--)
	            cout << v[i].first<<' ';
	    }
	    cout <<"\n";
	}
	return 0;
}

