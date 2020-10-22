package Stack;

import java.util.Stack;

public class AsteroidCollision {
    public int[] asteroidCollision(int[] arr) {
        Stack<Integer> s = new Stack<>();
        int n = arr.length;
        if(n==0 || n==1)
            return arr;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
                s.push(arr[i]);
            else
            {
                while(!s.isEmpty())
                {
                    if(s.peek()<0)
                    {
                        s.push(arr[i]);
                        break;
                    }

                    else
                    {
                        int top = s.peek();
                        if(top<Math.abs(arr[i]))
                        {
                            s.pop();
                        }  
                        else
                            break;
                    } 
                }
                if(!s.isEmpty() && s.peek()==Math.abs(arr[i]))
                    s.pop();
                else if(s.isEmpty())
                    s.push(arr[i]);

            }
        }
        int k = s.size();
        int[] a = new int[k];
        for(int i=k-1;i>=0;i--)
        {
            a[i] = s.pop();
        }
        return a;
    }
}
