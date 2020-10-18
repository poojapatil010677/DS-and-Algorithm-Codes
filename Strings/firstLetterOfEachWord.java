package Strings;

public class firstLetterOfEachWord {
    String firstAlphabet(String S) {
        // code here
        boolean b = true;
        String res = "";
        for(int i=0;i<S.length();i++)
        {
            if(S.charAt(i)==' ')
            {
                b = true;
            }
            else if(S.charAt(i)!=' ' && b==true)
            {
                res += S.charAt(i);
                b = false;
            }
        }
        return res;
    }
}
