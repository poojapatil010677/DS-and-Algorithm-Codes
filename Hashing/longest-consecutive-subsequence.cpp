/*

Longest Consecutive Subsequence 

Given an array A of integers. The task is to complete the function which returns an integer denoting the length of the longest sub-sequence such that elements in the sub-sequence are consecutive integers, the consecutive numbers can be in any order.

Input:
2
7
1 9 3 10 4 20 2
11
36 41 56 35 44 33 34 92 43 32 42
Output:
4
5

*/

int findLongestConseqSubseq(int arr[], int n)
{
    //Your code here
    set<int> s;
    for(int i=0;i<n;i++)
        s.insert(arr[i]);
    
    int res = 0;
    
    for(int i=0;i<n;i++)
    {
        if(s.find(arr[i]-1)==s.end())
        {
            int j = arr[i];
            while(s.find(j)!=s.end())
                j++;
                
            res = max(res,j-arr[i]);
        }
    }
    return res;
}
