/*

Reverse a string using stack.

An string of words is given, the task is to reverse the string using stack.

*/

void reverse(char *str, int len)
{
    // Your code goes here
    stack<char> s;
    for(int i=0;i<len;i++)
    {
        s.push(str[i]);
    }
    for(int i=0;i<len;i++)
    {
        str[i] = s.top();
        s.pop();
    }

}
