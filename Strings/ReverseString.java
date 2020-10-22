package Strings;

import java.util.*;


public class ReverseString {
    public static void main (String[] args) {
		Scanner scan  = new Scanner(System.in);
		int t = scan.nextInt();
		//System.out.println(t);
		while(t>0)
		{
		    t = t-1;
		    String s = scan.next();
		    StringBuffer sb = new StringBuffer(s);
		    sb.reverse();
		    System.out.println(sb);
		}
	}
}
