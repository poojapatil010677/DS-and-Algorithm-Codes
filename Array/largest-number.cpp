/*

Largest Number

Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/

int compare(int a,int b)
{
    string x = to_string(a);
    string y = to_string(b);
    string xy = x.append(y);
    string yx = y.append(x);
    return (xy.compare(yx)>0?1:0);
}
string Solution::largestNumber(const vector<int> &arr) {
    vector<int> A = arr;
    int i;
    for(i=0;i<A.size();i++)
        if(A[i]!=0) break;
    if(i==A.size()) return "0";
    sort(A.begin(),A.end(),compare);
    string res = "";
    for(int i=0;i<A.size();i++)
        res = res.append(to_string(A[i]));
    return res;
}

