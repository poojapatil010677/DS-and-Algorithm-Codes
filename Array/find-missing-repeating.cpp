/*

Find missing and repeating 

Given an unsorted array of size N of positive integers. One number 'A' from 
set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these 
two numbers.

Note: If you find multiple answers then print the Smallest number found.
 Also, expected solution is O(n) time and constant extra space.

*/

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&arr[i]);
	    }
	    
	    int miss = -1;
	    int repeat = -1;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(arr[abs(arr[i])-1]>0)
	            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
	        else
	            repeat = abs(arr[i]);
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>0)
	            miss = i+1;
	    }
	    cout << repeat<<' '<< miss<<"\n";
	}
	return 0;
}
