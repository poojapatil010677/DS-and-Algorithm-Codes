/*

Evaluation of postfix expression

Given a postfix expression, the task is to evaluate the expression and print the final value. Operators will only include the basic arithmetic operators like *,/,+ and -.

Input:
2
231*+9-
123+*8-
Output:
-4
-3

*/

// The main function that returns value of a given postfix expression
int evaluatePostfix(string &str)
{
    // Your code here
    stack<int> s;
    if(str.length()==0) return 0;
    
    int n = str.length();
    for(int i=0;i<n;i++)
    {
        if(isdigit(str[i]))
            s.push(str[i]-'0');
        else
        {
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();
            
            switch(str[i])
            {
                case '+' : s.push(val1+val2);break;
                case '-' : s.push(val2-val1);break;
                case '*' : s.push(val1*val2);break;
                case '/' : s.push(val2/val1);break;
            }
        }
    }
    return s.top();
}
