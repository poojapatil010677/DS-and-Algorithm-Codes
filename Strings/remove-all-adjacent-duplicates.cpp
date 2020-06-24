/*

Remove all the adjacent duplicates in string

Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

Input: "abbaca"
Output: "ca"

*/

string removeDuplicates(string str) {
        
        int n = str.length();
        if(n==0) return str; 
        
        stack<char> s;
        for(int i=0;i<n;i++)
        {
            if(s.empty()) s.push(str[i]);
            else if(s.top()==str[i]) s.pop();
            else s.push(str[i]);
        }
        
        string temp;
        while(!s.empty())
        {
            temp+=s.top();
            s.pop();
        }
        string res;
        for(int i=temp.length()-1;i>=0;i--)
        {
            res+=temp[i];
        }
        return res;
}
