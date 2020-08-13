/*

Given an string A. The only operation allowed is to insert characters in the beginning of the string.

Find how many minimum characters are needed to be inserted to make the string a palindrome string.

Input 1:
    A = "ABC"
Output 1:
    2
    Explanation 1:
        Insert 'B' at beginning, string becomes: "BABC".
        Insert 'C' at beginning, string becomes: "CBABC".

Input 2:
    A = "AACECAAAA"
Output 2:
    2
    Explanation 2:
        Insert 'A' at beginning, string becomes: "AAACECAAAA".
        Insert 'A' at beginning, string becomes: "AAAACECAAAA".

*/


int Solution::solve(string A) {
    string rev = A;
    reverse(rev.begin(),rev.end());
    string concat = A + '$' + rev;
    
    int n = concat.length();
    int lps[n];
    lps[0] = 0;
    int i = 1;
    int len = 0;
    while(i<n)
    {
        if(concat[i]==concat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    int res = A.length()-lps[n-1];
    return res;
}


