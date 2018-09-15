/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc=new Scanner(System.in);
	    long n=sc.nextLong();
	    long m=sc.nextLong();
	    if(n==1){
	        System.out.println("1");
	    }else{
	        if(m-1<n-m){
	            System.out.println(m+1);
	        }else{
	            System.out.println(m-1);
	        }
	    }
	    
	}
}