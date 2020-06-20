/*

Next Larger Element

Given an array A[] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. If no such element exists, output -1.

Input
2
4
1 3 2 4
5
6 8 0 1 3
Output
3 4 4 -1
8 -1 1 3 -1

*/

vector <long long> nextLargerElement(long long arr[], int n){
    // Your code here
    vector<long long> res(n);
    stack<long long> s;
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && s.top()<=arr[i])
            s.pop();
            
        if(s.empty())
            res[i] = -1;
        
        else
            res[i] = s.top();
            
        s.push(arr[i]);
    }
    return res;
}
