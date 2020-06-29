/*

Merge-sort 

Time-complexity : O(nlogn)

*/

void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
} 

// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
     // Your code here
     int temp[r-l+1];
     int i = l;
     int k = 0;
     int j =m+1;
     while(i<=m && j<=r)
     {
         if(arr[i]<arr[j])
         {
             temp[k++] = arr[i++];
         }
         else
         {
             temp[k++] = arr[j++];
         }
     }
     while(i<=m)
     {
         temp[k++] = arr[i++];
     }
     while(j<=r)
     {
         temp[k++] = arr[j++];
     }
     i = l;
     k = 0;
     while(i<=r)
     {
         arr[i++] = temp[k++];
     }
}
