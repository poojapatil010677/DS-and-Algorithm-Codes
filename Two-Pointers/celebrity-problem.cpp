/*

The Celebrity Problem

You are in a party of N people, where only one person is known to everyone. Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. Your task is to find the stranger (celebrity) in party.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Example:
Input :
2
3
0 1 0 0 0 0 0 1 0
2
0 1 1 0
Output :
1
-1

*/

int getId(int M[MAX][MAX], int n)
{
    //Your code here
    int a = 0;
    int b = n-1;
    
    while(a<b)
    {
        if(M[a][b])
            a++;
        else
            b--;
    }
    
    for(int i=0;i<n-1;i++)
    {
        if(i!=a &&(M[a][i] || !M[i][a])) return -1;
    }
    return a;
}
