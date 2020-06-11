/*

Reverse array in groups

Given an array arr[] of positive integers of size N. Reverse every sub-array of K group elements.

Input
4
5 3
1 2 3 4 5
4 3
5 6 8 9
4 7
5 6 8 9
8 3
1 2 3 4 5 6 7 8

Output
3 2 1 5 4
8 6 5 9
9 8 6 5
3 2 1 6 5 4 8 7

*/

void reverse(vector<long long> mv, vector<long long> &res,int i, int n, int k)
{
    int p = i;
    int j = k+i-1;
    if(j>=n) j = n-1;
    for(j;j>=i;j--)
    {
        res[p++] = mv[j];
    }
}

// Function to reverse the array in groups
vector<long long> reverseInGroups(vector<long long> mv, int n, int k){
    
    // your code here
    vector<long long> res(n,0);
    int i = 0;
    while(i<n)
    {
        reverse(mv,res,i,n,k);
        i = i+k;
    }
    return res;
    
    
}
