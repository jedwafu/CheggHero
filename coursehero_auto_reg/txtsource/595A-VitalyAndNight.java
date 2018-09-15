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
	    int floor=sc.nextInt();
	    int rooms=sc.nextInt();
	    int bit=0;
	    int total=0;
	    int val;
	    int flag=0;
	    for(int i=0;i<floor;i++){
	        for(int j=0;j<2*rooms;j++){
	            val=sc.nextInt();
	            if(val==1){
	               bit=1;
	            } flag++;
	            if(flag==2){
	               if(bit==1){
	                   total++;
	                   bit=0;
	                   flag=0;
	               }else{
	                   bit=0;
	                   flag=0;
	               }
	            }
	           
	        }
	    }
        System.out.println(total);
	}
}