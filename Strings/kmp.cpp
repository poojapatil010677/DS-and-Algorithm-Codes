/*

check if the strings are rotations of each other or not

Given two strings s1 and s2. The task is to check if s2 is a rotated version of the string s1. The characters in the strings are in lowercase.

*/

bool areRotations(string s1,string s2)
{

    int n1 = s1.length();
    int n2 = s2.length();
    
    if(n1!=n2) return false;
    
    int lps[n1];
    lps[0] = 0;
    
    int i = 1;
    int len = 0;
    
    while(i<n1)
    {
        if(s1[i]==s2[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        
        else
        {
            if(len!=0)
                len = lps[len-1];
                
            else
            {
                lps[i] = 0;
                i++;
            }
        }
        
    }
    
    i = 0;
    for(int j=lps[n1-1];j<n2;j++)
    {
        if(s1[i++]!=s2[j])
            return false;
    }
    return true;
}
