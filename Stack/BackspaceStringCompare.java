package Stack;

import java.util.Stack;

public class BackspaceStringCompare {
    public boolean backspaceCompare(String S, String T) {
        Stack<Character> s = new Stack<Character>();
        Stack<Character> t = new Stack<Character>();
        
        for(char c: S.toCharArray())
        {
            if(c!='#')
                s.push(c);
            else if(!s.isEmpty())
                s.pop();
        }
        
        for(char c:T.toCharArray())
        {
            if(c!='#')
                t.push(c);
            else if(!t.isEmpty())
                t.pop();
        }
        
        while(!s.isEmpty())
        {
            char curr = s.pop();
            if(t.isEmpty() || t.pop()!=curr)
                return false;
        }
        return s.isEmpty() && t.isEmpty();
    }
}
