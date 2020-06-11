/*
Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Example:
Sample Input:
2
4
0 3 1 2
5
2 3 1 2 3 

Sample Output:
-1
2 3 

*/

vector<int> duplicates(int a[], int n) {
    // code here
    int index;
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        index = (a[i]%n);
        a[index]+=n;
    }
    for(int i=0;i<n;i++)
    {
        if((a[i]/n)>=2)
        {
            res.push_back(i);
        }
    }
    if(res.size()==0){
        res.push_back(-1);
    }
    return res;
}
