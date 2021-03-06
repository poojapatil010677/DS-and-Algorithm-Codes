/*

Is subsequence

Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original 
string by deleting some (can be none) of the characters without disturbing the
relative positions of the remaining characters. (ie, "ace" is a subsequence of
"abcde" while "aec" is not).

Input: s = "abc", t = "ahbgdc"
Output: true

*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        if(n2<n1) return false;
        int i = 0;
        int j = 0;
        while(i<n1 && j<n2)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            j++;
        }
        if(i==n1) return true;
        return false;
    }
};
