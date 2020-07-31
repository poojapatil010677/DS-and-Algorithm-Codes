/*

Add Digits

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.

*/

class Solution {
public:
    int addDigits(int num) {
        if(num<10) return num;
        while(num>9)
        {
            int s = 0;
            int temp = num;
            while(temp>0)
            {
                s = s + (temp%10);
                temp = temp/10;
            }
            num = s;
        }
        return num;
    }
};
