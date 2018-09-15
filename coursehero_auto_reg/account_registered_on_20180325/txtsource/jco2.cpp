#include<bits/stdc++.h>
using namespace std;


int num[100000];
char s[100001];
int sum;
	
int main()
{
	int t,len,i,n,k,l,flag,neg;
	char c;
	
	cin>>t;
	while(t--)
	{
		neg=0;
		flag=1;
		k=0;
		sum=0;
		
		
		scanf("%s",s);
			    
	    len=strlen(s);
	    cin>>n;
	    
	    if(s[0]=='(')
	    {
	    	num[0]=-1;
		}
		else
		num[0]=1;
		
	    for(i=1;i<len;i++)
	    {
	    	if(s[i]==s[i-1])
	    	{
	    		if(s[i]=='(')
	    		num[k]+=-1;
			
			    else
			    num[k]+=1;
			
		    }
		    else
		    {
		    	
		    	k++;
		    	if(s[i]=='(')
		    	num[k]=-1;
		    	else
		    	num[k]=1;
			}
		}
		
		k++;
		
		for(i=0;i<k;i++)
		{
			if(num[i]>0)
			{
				neg++;
			}
			
			sum+=num[i];
			
			if(sum>0)
			flag=0;
			 
		}
			 
		if(flag==1 && sum==0)
		{
			flag=1;
		}
		
	    else flag=0;
		
		
		
		if(flag==0 && n==1)
		{
			puts(s);
			cout<<endl;
		}
		
		else if(flag==0 && n!=1)
		{
			cout<<-1<<endl;
		}
		
		else
		{  
			if(n>k)
			cout<<-1<<endl;
			
			else
			{
				if(n<=neg)
				{
					i=n;
					l=0;
				  while(i>0)
				  {
				  	
					if(num[l]>0)
					i--;
		
					l++;
				  }
				  num[l-1]--;
			   }
			   
			   else
			   {
			   	i=n-neg;
			   	l=k-1;
			   	
			   	while(i>0)
			   	{
			   		if(num[l]<0)
			   		i--;
			   		
			   		l--;
				   }
				   
				   num[l+1]++;
			   }
			   
			   for(i=0;i<k;i++)
			   {
			   	while(num[i]<0)
			   	{
			   		cout<<"(";
			   		num[i]++;
				   }
				   
				   while(num[i]>0)
				   {
				   	 cout<<")";
				   	 num[i]--;
				   }
			   }
			   cout<<endl;
			}
		}
	}
	
	return 0;
	
}
