/*
Problem Description

Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

 A = [3, 5, 4, 2]
2

*/

bool compare(pair<int,int> a,pair<int,int> b)
{
    return a.first<b.first;
}
int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int,int>> temp;
    for(int i=0;i<A.size();i++)
        temp.push_back({A[i],i});
    sort(temp.begin(),temp.end(),compare);
    int n = A.size()-1;
    int maxindex[n+1];
    int index = INT_MIN;
    for(int i=n;i>=0;i--)
    {
        index = max(index,temp[i].second);
        maxindex[i] = index;
    }
    int res = 0;
    for(int i=0;i<=n;i++)
    {
        res = max(res,maxindex[i]-temp[i].second);
    }
    return res;
}

