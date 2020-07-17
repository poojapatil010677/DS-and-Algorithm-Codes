/*

Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

For Example:
If the matrix is    

1 2 3
4 5 6
7 8 9
The output should Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]
i.e print the elements of array diagonally.

Note: The input array given is in single line and you have to output the answer in one line only.

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    vector<vector<int>> v(n);
	    for(int i=0;i<n;i++)
	    {
	        vector<int> temp(n);
	        for(int j=0;j<n;j++)
	        {
	            cin >> temp[j];
	        }
	        v[i] = temp;
	    }
	    //int turn = (n*n)-1;
	    for(int k=0;k<n;k++)
	    {
	        for(int i=0,j=k;i<n && j>=0;i++,j--)
	        {
	            cout << v[i][j] <<' ';
	        }
	    }
	    for(int k=1;k<n;k++)
	    {
	        for(int i=k,j=n-1;i<n && j>=0;i++,j--)
	        {
	            cout << v[i][j] <<' ';
	        }
	       
	    }
	     cout << '\n';
	}
	return 0;
}
