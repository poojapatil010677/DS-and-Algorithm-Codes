package Array;
//https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

import java.util.Scanner;

public class Sort012 {
    public static void main (String[] args) {
		int t;
		Scanner scan = new Scanner(System.in);
		t = scan.nextInt();
		while(t>0)
		{
		    t = t-1;
		    int n = scan.nextInt();
		    int[] arr = new int[n];
		   for(int i=0;i<n;i++)
		   {
		       arr[i] = scan.nextInt();
		   }
		   int s,m,e;
		   s=0;
		   m=0;
           e=n-1;
           int temp = 0;
		   while(m<=e)
		   {
		       if(arr[m]==0)
		       {
                   temp = arr[m];
                   arr[m] = arr[s];
                   arr[s] = temp;
		           m = m + 1;
		           s = s + 1;
		       }
		       if(arr[m]==1)
		       m = m + 1;
		       
		       if(arr[m]==2)
		       {
                    temp = arr[m];
                    arr[m] = arr[e];
                    arr[e] = temp;
		           e = e - 1;
		       }
		   }
		   for(int i=0;i<n;i++)
		   {
		       System.out.print(arr[i]+' ');
		   }
		   System.out.println();
		}
	}
    
}
