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
	    int n=sc.nextInt();
	    int m=sc.nextInt();
	    int res=0;
	    int p;
	    if(n%2!=0){
	        p=n/2;
	        p++;
	    }else{
	        p=n/2;
	    }
	    for(int i=p;i<=n;i++){
	        if(i%m==0){
	            res=i;
	            break;
	        }
	    }
	    if(res>0){
	        System.out.println(res);
	    }else{
	        System.out.println("-1");
	    }
	}
}