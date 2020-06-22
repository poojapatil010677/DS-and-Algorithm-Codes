/*

Max distance between same elements 

Given an array with repeated elements, the task is to find the maximum distance between two occurrences of an element.

Input

2
6
1 1 2 2 2 1
12
3 2 1 2 1 4 5 8 6 7 4 2

Output

5
10

*/


// your task is to complete this function
int maxDistance(int arr[], int n)
{
    //Code here
    if(n==0) return 0;
    
    unordered_map<int,pair<int,int>> m;
    
    for(int i=0;i<n;i++)
    {
        if(m.find(arr[i])==m.end())
        {
            m[arr[i]] = {i,i};
        }
        else
         m[arr[i]].second = i;
    }
    
    int maxm = INT_MIN;
    
    for(auto it:m)
    {
        if(it.second.second-it.second.first>maxm)
        {
            maxm = it.second.second-it.second.first;
        }
    }
    return maxm;
}
