/*

Given a matrix mat[] of size n x m, where every row and column is sorted in increasing order, and a number x is given. The task is to find whether element x is present in the matrix or not.

*/

/*  Function to search x in the input matrix
*   n, m: rows and columns of matrix
*   x: element to check presence in matrix
*   mat[][]: input matrix
*/
int search( int n,int m, int x, int mat[SIZE][SIZE])
{
   // Your code here
   int i,j;
   i=0;
   j=m-1;
   while(i<n && j>=0)
   {
       if(mat[i][j]==x)
            return 1;
        else if(mat[i][j]>x)
            j--;
        else if(mat[i][j]<x)
            i++;
   }
   return 0;
}
