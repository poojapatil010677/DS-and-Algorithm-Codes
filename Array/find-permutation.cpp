/*

Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

Length of given string s will always equal to n - 1
Your solution should run in linear time and space.

Input 1:

n = 3

s = ID

Return: [1, 3, 2]

*/

vector<int> Solution::findPerm(const string A, int B) {
    vector<int> res;
    int small = 1;
    int large = B;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='I')
        {
            res.push_back(small);
            small++;
        }
        else
        {
            res.push_back(large);
            large--;
        }
    }
    if(A[A.size()-1]=='I')
        res.push_back(large);
    else
        res.push_back(small);
    return res;
}



