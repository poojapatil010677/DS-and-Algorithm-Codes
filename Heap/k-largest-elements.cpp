/*

K largest elements

Given an array of N positive integers, print k largest elements from the array.  
The output elements should be printed in decreasing order.

Input:
2
5 2
12 5 787 1 23
7 3
1 23 12 9 30 2 50

Output:
787 23
50 30 23

*/


#include <iostream>
using namespace std;

void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr,int p,int n)
{
    //if(p>=n) return;
    int largest = p;
    int l = (p*2)+1;
    int r = (p*2)+2;
    if(l<n && arr[l]>arr[largest])
        largest = l;
    if(r<n && arr[r]>arr[largest])
        largest = r;
    if(largest!=p)
    {
        swap(arr[p],arr[largest]);
        heapify(arr,largest,n);
    }
    
}

void build_heap(int* arr,int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,i,n);
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    build_heap(arr,n);
	    int m = n;
	    for(int i=n-1;i>=n-k;i--)
	    {
	        cout<<arr[0]<<' ';
	        swap(arr[0],arr[i]);
	        m = m-1;
	        heapify(arr,0,m);
	    }
	    cout << "\n";
	}
	return 0;
}
