/*

Matrix Median

Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.

Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.

*/

int Solution::findMedian(vector<vector<int> > &A) {
    int minm = INT_MAX;
    int maxm = INT_MIN;
    int r = A.size();
    int c = A[0].size();
    
    for(int i=0;i<r;i++)
    {
        minm = min(minm,A[i][0]);
        maxm = max(maxm,A[i][c-1]);
    }
    
   // cout<<minm<<' '<<maxm<<'\n';
    
    int desire = (r*c+1)/2;
    int counter = 0;
    
    while(minm<maxm)
    {
        counter = 0;
        int mid = (minm + maxm)/2;
        for(int i=0;i<r;i++)
        {
            counter= counter + (upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin());
        }
        if(counter<desire)
            minm = mid+1;
        else
            maxm = mid;
    }
    return minm;
}
