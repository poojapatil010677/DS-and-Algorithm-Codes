/*

Given two strings of lowercase alphabets and a value K, your task is to complete the given 
function which tells if  two strings are K-anagrams of each other or not.
Two strings are called K-anagrams if both of the below conditions are true.
1. Both have same number of characters.
2. Two strings can become anagram by changing at most K characters in a string.

Input:
1
fodr gork
2
Output:
1

Explanation:
Testcase1: change fd to gk
*/

/*Complete the function below*/
bool areKAnagrams(string str1, string str2, int k)
  {
    int l1 = str1.length();
    int l2 = str2.length();
    if(l1!=l2) return false;
    
    int visit[26] = {0};
    for(int i=0;i<l1;i++)
        visit[str1[i]-'a']++;
    int count = 0;
    for(int i=0;i<l2;i++)
    {
        if(visit[str2[i]-'a']==0)
            count++;
        else
            visit[str2[i]-'a']--;
    }
    if(count<=k)return true;
    return false;
   }
