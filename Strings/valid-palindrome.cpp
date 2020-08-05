/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Input: "A man, a plan, a canal: Panama"
Output: true

Input: "race a car"
Output: false

*/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s=="")return true;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int i = 0;
        int j = s.length()-1;
        while(i<j)
        {
            while((i<j) && (!isdigit(s[i]) && !isalpha(s[i])))
                i++;
            while((i<j) && (!isdigit(s[j]) && !isalpha(s[j])))
                j--;
            if(s[i]!=s[j]) return false;
            else
                i++;j--;
        }
        return true;
    }   
};
