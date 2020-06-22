/*

Multiply strings

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"

*/

string multiply(string num1, string num2) {
        int n1 = num1.length();
        int n2 = num2.length();
        
        vector<int> res(n1+n2,0);
        int sum = 0,carry=0;
        int i_n1 = 0;
        int i_n2 = 0;
        
        for(int i=n2-1;i>=0;i--)
        {
            int a = num2[i]-'0';
            carry = 0;
            i_n2 = 0;
            for(int k=n1-1;k>=0;k--)
            {
                int b = num1[k]-'0';
                sum = (a*b) + carry + res[i_n1+i_n2];
                carry = sum/10;
                sum = sum%10;
                res[i_n1+i_n2]=sum;
                i_n2++;
            }
            
            if(carry>0)
                res[i_n1+i_n2]+=carry;
            
            i_n1++;
        }
        
        int i = res.size()-1;
        while(i>=0 && res[i]==0)
            i--;
        
        if(i==-1)
            return "0";
        
        string result = "";
        while(i>=0)
        {
            result+=std::to_string(res[i]);
            i--;
        }
        return result;
    }
