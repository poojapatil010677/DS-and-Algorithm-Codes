/*

Two Sum 

Given an array of positive integers and an integer. Determine whether or not there exist two elements in A whose sum is exactly equal to that integer.

Input:
2
6 16
1 4 45 6 10 8
5 10
1 2 4 3 6
Output:
Yes
Yes

*/

bool keypair(vector<int> A, int N, int X) {
    // Your code goes here
    unordered_set<int> s;
    for(int i=0;i<N;i++)
    {
        int temp = X-A[i];
        if(s.find(temp)!=s.end())
            return true;
        s.insert(A[i]);
    }
    return false;
}

