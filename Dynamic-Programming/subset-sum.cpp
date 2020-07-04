/*

Subset sum problem

*/

#include <iostream>
using namespace std;

bool subset(int arr[],int sum, int n)
{
    bool dp[n+1][sum+1];
    
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = true;
    }
    
    for(int j=1;j<=sum;j++)
        dp[0][j] = false;
        
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<arr[i-1])
                dp[i][j] = dp[i-1][j];
            if(j>=arr[i-1])
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
        }
    }
    return dp[n][sum];
}

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
	    int sum = 0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
	    if(sum%2==1)
	        printf("%s\n","NO");
	   else
	   {
	       bool res = subset(arr,sum/2,n);
	       if(res)
	            printf("%s\n","YES");
	       else
	            printf("%s\n","NO");
	   }
	}
	return 0;
}
