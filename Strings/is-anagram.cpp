/*

Anagram

Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, “act” and “tac” are an anagram of each other.

*/

bool isAnagram(string s1, string s2){
    
    unordered_map<char,int> m;
    
    int n1 = s1.length();
    int n2 = s2.length();
    
    if(n1!=n2) return false;
    
    for(int i=0;i<n1;i++)
    {
        if(m.find(s1[i])==m.end())
            m[s1[i]] = 1;
        
        else
            m[s1[i]]++;
    }
    
    for(int i=0;i<n1;i++)
    {
        if(m.find(s2[i])==m.end()) return false;
        
        else if(m[s2[i]]==0) return false;
        
        else
            m[s2[i]]--;
    }
    return true;
}

