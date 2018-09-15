#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int t;
	long long int T1,T2,t1,t2;
	float ans1,ans2,temp;
	
	cin>>t;
	
	while(t--)
	{
	  cin>>T1>>T2>>t1>>t2;
	  
	  ans1=0;
	  ans2=0;
	  if(t1==0 && t2==0)
	  ans1=ans2=1/2.0;
	  
	  
	  else if(T1>T2 && t2<T1-T2)
	  {
	  	if(T2>=t1)
	  {
	    ans1=(T2-t1)/(float)T2;
	   	ans1=ans1/T1;
	   	ans1=ans1*(T2-t1);
	   	ans1=ans1/2.0;
	  }
	  
	  if(T1>=t2)
	   {
	   ans2=T2/(float)T1;
	   ans2=ans2/2.0;
	   ans2=ans2+(T1-T2-t2)/(float)T1;
	   }
	    
	  }
	  
	  else if(T2>T1 && t1<T2-T1)
	  {
	  	if(T1>=t2)
	  {
	    ans2=(T1-t2)/(float)T1;
	   	ans2=ans2/T2;
	   	ans2=ans2*(T1-t2);
	   	ans2=ans2/2.0;
	  }
	    if(T2>=t1)
	   {
	   ans1=T1/(float)T2;
	   ans1=ans1/2.0;
	   ans1=ans1+(T2-T1-t1)/(float)T2;
	   }
	  
      }
      
      else
	  {
	  if(T2>=t1)
	  {
	    ans1=(T2-t1)/(float)T2;
	   	ans1=ans1/T1;
	   	ans1=ans1*(T2-t1);
	   	ans1=ans1/2.0;
	  }
	  
	  if(T1>=t2)
	  {
	  	ans2=(T1-t2)/(float)T1;
	   	ans2=ans2/T2;
	   	ans2=ans2*(T1-t2);
	   	ans2=ans2/2.0;
	  }
	  
      }
      
	  printf("%.6f\n",1-(ans1+ans2));
	  
    }
    
    return 0;
}
