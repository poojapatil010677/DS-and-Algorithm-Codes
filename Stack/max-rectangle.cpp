/*

Max Rectangle

Given a binary matrix. Find the maximum area of a rectangle formed only of 
1s in the given matrix.

Input
1
4 4 
0 1 1 0 1 1 1 1 1 1 1 1 1 1 0 0

Output
8

*/

int maxHist(int a[],int n)
{
    stack<int> s;
    int max_area = 0;
    int area = 0;
    int i = 0;
    while(i<n)
    {
        if(s.empty() || a[i]>=a[s.top()])
        {
            s.push(i++);
        }
        else
        {
            int tp = s.top();
            s.pop();
            
            area = a[tp] * (s.empty() ? i : i-s.top()-1);
            if(area>max_area)
                max_area = area;
        }
    }
    while(!s.empty())
    {
        int tp = s.top();
        s.pop();
        
        area = a[tp] * (s.empty() ? i : i-s.top()-1);
        if(area>max_area)
        max_area = area;   
    }
    return max_area;
}

int maxArea(int M[MAX][MAX], int n, int m) {
    int res = maxHist(M[0],m);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(M[i][j]) 
                M[i][j] = M[i-1][j] + M[i][j];
        }
        res = max(res,maxHist(M[i],m));
    }
    return res;
}

