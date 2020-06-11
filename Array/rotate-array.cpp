/*

Rotate Array

Given an unsorted array arr[] of size N, rotate it by D elements in the counter-clockwise direction. 

Expected time complexity : O(n)
Expected space complexity : O(1)

*/

// Juggling Algorithm


int gcd(int a, int b)
{
    if(b==0) return a;
    else
    return gcd(b,a%b);
}

// This function rotate array by D elements
// arr: input elements
// n: size of the array
void rotateArr(int arr[], int d, int n){
    
   // Your code here
   d = d%n;
   int g = gcd(n,d);
   int j,k;
   for(int i=0;i<g;i++)
   {
       int temp = arr[i];
       j = i;
       while(1)
       {
            k = j+d;
            if(k>=n)
                k = k-n;
            if(k==i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
   }
    
}

