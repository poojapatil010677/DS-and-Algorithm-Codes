/*

Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

*/

bool isValid(string s) {
        stack<int> st;
        int l = s.length();
        for(int i=0;i<l;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
                printf("%c",s[i]);
            }
            else
            {
                if(st.empty()) return false;
                char temp = st.top();
                st.pop();
                if(s[i]==')' && temp!='(')
                    return false;
                else if(s[i]=='}' && temp!='{')
                    return false;
                else if(s[i]==']' && temp!='[')
                    return false;
            }
        }
        return (st.empty()); 
    }
