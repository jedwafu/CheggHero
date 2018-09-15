/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    //The problem is to tell whether there exists a regular polygon with angle equal to a.
        Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++){
		    int a=sc.nextInt();
		    if(360%(180-a)==0){
		       System.out.println("YES");
		    }else{
		        System.out.println("NO");
		    }
		}
	}
}