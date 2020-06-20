/*

Palindrome Number

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        
        if(x==0) return true;
        
        long long rev = 0;
        int temp = x;
        while(temp!=0)
        {
            rev = (rev*10) + temp%10;
            temp = temp/10;
        }
        
        if(rev == x) return true;
        else return false;
        
    }
};
