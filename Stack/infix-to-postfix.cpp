/*
Infix to Postfix

Given an infix expression in the form of string str. Conver this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
​Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 

Example:
Input:
2
a+b*(c^d-e)^(f+g*h)-i
A*(B+C)/D
Output:
abcd^e-fgh*+^*+i-
ABC+*D/

*/

int prec(char ch)
{
    if(ch=='^') return 3;
    if(ch=='*' || ch=='/') return 2;
    if(ch=='+' || ch=='-') return 1;
    if(ch=='$') return -1;
    if(ch=='(') return 0;
}

// The main function to convert infix expression
//to postfix expression
string infixToPostfix(string s)
{
    // Your code here
    int n = s.length();
    stack<char> st;
    st.push('$');
    string res = "";
    for(int i=0;i<n;i++)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
            res+=s[i];
        else
        {
            if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')')
            {
                while(st.top()!='(')
                {
                    res+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                if(prec(s[i])>prec(st.top()))
                    st.push(s[i]);
                else
                {
                    while(prec(st.top())>=prec(s[i]))
                    {
                        res+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
    }
    while(st.top()!='$')
    {
        res+=st.top();
        st.pop();
    }
    return res;
    
}
