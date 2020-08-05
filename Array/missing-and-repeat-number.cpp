/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int xor1 = A[0];
    for(int i=1;i<n;i++)
        xor1 = xor1^A[i];
    for(int i=1;i<=n;i++)
        xor1 = xor1^i;
    int setbit = xor1 & ~(xor1-1);
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]&setbit)
            x = x^A[i];
        else
            y = y^A[i];
    }
    
    for(int i=1;i<=n;i++)
    {
        if(i&setbit)
            x = x^i;
        else
            y = y^i;
    }
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        if(x==A[i])
        {
            res.push_back(x);
            res.push_back(y);
            return res;
        }
    }
    res.push_back(y);
    res.push_back(x);
    return res;
    
}


