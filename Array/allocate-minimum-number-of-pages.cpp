/*

Allocate minimum number of pages

You are given N number of books. Every ith book has Pi number of pages. 
You have to allocate books to M number of students. There can be many ways or permutations to do so. In each permutation one of the M students will be allocated 
the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student 
is minimum of those in all the other permutations, and print this minimum value. 
Each book will be allocated to exactly one student. Each student has to be allocated atleast one book.
Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see explanation for better understanding).

Input:
2
4
12 34 67 90
2
3
15 17 20
2
Output:
113
32
*/

#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool isvalid(ll arr[],ll n,ll k,ll mid)
{
    int painters = 1;
    int curr = 0;
    for(int i=0;i<n;i++)
    {
        if(curr+arr[i]>mid)
        {
            curr = arr[i];
            painters++;
            if(painters>k)
                return false;
        }
        else
        {
            curr = curr + arr[i];
        }
    }
    return true;
}

ll search(ll arr[],ll n,ll k)
{
    if(k>n) return -1;
    ll lo = INT_MIN;
    ll hi = 0;
    for(int i=0;i<n;i++)
    {
        hi = hi + arr[i];
        lo = max(lo,arr[i]);
    }
    ll ans = lo;
    while(lo<=hi)
    {
        ll mid = (lo+hi)/2;
        if(isvalid(arr,n,k,mid))
        {
            ans = mid;
            hi = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        ll k;
        cin>>k;
        
        ll ans = search(arr,n,k);
        cout<<ans<<'\n';
    }
}

