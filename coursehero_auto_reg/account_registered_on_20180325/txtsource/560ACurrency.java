/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    int arr[]=new int[1001];
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=0;i<n;i++){
		    arr[i]=sc.nextInt();
		}
		int flag=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]==1)
	            flag=1;
	    }
	    if(flag!=0)
	    System.out.println("-1");
	    else
	    System.out.println("1");
	}
}
