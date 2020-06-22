/*

Isomorphic strings

Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’

Input:
2
aab
xxy
aab
xyz
Output:
1
0

*/

bool areIsomorphic(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    
    if(n1!=n2) return false;
    set<char> seen;
    unordered_map<char,char> m;
    for(int i=0;i<n1;i++)
    {
        if(m.find(s1[i])==m.end())
        {
            if(seen.find(s2[i])!=seen.end()) return false;
            m[s1[i]] = s2[i];
            seen.insert(s2[i]);
        }
            
        else if(s2[i]!=m[s1[i]])
            return false;
    }
    return true;
}
