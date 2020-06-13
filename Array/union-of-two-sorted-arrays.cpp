/*

Union of Two Sorted Arrays

Given two sorted arrays arr[] and brr[] of size N and M respectively. The task is to find the union of these two arrays.
Union of two arrays can be defined as the common and distinct elements in the two arrays.

Expected Time Complexity: O(N+M).
Expected Auxiliary Space: O(N+M).

Example:
Input:
3
5 3
1 2 3 4 5
1 2 3
5 5
2 2 3 4 5
1 1 2 3 4
5 5
1 1 1 1 1
2 2 2 2 2
Output:
1 2 3 4 5
1 2 3 4 5
1 2

*/

//arr1,arr2 : the arrays
// n, m: size of arrays
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    //Your code here
    //return vector with correct order of elements
    vector<int> res;
    int i=0;
    int j=0;
    while(i<n && j<m)
    {
        if(arr1[i]==arr2[j])
        {
            res.push_back(arr1[i]);
            i++;
            j++;
            while(i<n && arr1[i]==arr1[i-1])
            i++;
            while(j<m && arr2[j]==arr2[j-1])
            j++;
        }
        else
        {
            if(arr1[i]<arr2[j])
            {
                res.push_back(arr1[i]);
                i++;
                while(i<n && arr1[i]==arr1[i-1])
                i++;                
            }
            else
            {
                res.push_back(arr2[j]);
                j++;
                while(j<m && arr2[j]==arr2[j-1])
                j++;
            }
        }
    }
    while(i<n)
    {
        res.push_back(arr1[i]);
        i++;
        while(i<n && arr1[i]==arr1[i-1])
        i++;
        
    }
    while(j<m)
    {
        res.push_back(arr2[j]);
        j++;
        while(j<m && arr2[j]==arr2[j-1])
        j++;
    }
    return res;
    
}
