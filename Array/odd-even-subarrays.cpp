/*

You are given an array A of N positive integer values. A subarray of this array is called Odd-Even subarray if the number of odd integers in this subarray is equal to the number  of even integers in this subarray.

Find the number of Odd-Even subarrays for the given array.

*/

#include<iostream>
#include<unordered_map>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	long int n;
	cin>>n;
	long long int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int bin[n];
	for(int i=0;i<n;i++)
	{
		if(arr[i]%2==0)
			bin[i] = 1;
		else
			bin[i] = -1;
	}
	unordered_map<long long,long long> m;
	m[0] = 1;
	long long int curr_sum = 0;
	long long int res = 0;
	for(int i=0;i<n;i++)
	{
		curr_sum = curr_sum + bin[i];
		if(m.find(curr_sum)==m.end())
		{
			m[curr_sum] = 1;
		}
		else
		{
			res = res + m[curr_sum];
			m[curr_sum]++;
		}
	}
	cout<<res<<'\n';
}
