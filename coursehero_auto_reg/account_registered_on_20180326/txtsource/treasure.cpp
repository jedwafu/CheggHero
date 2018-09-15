#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
	char array[100000];
	int i;
	int dif[100000],hash=0,test=0,count;
	
	
	gets(array);
	int len=strlen(array);
	
	if(array[0]=='(')
	dif[0]=1;
	
	
	else 
	{
		cout<<-1;
		return 0;
	}
	
	for(i=1;i<len;i++)
	{
		if(array[i]=='(')
		dif[i]=dif[i-1]+1;
		
		else if(array[i]==')')
		dif[i]=dif[i-1]-1;
		
		else
		{
		dif[i]=dif[i-1]-1;
		test=1;
		count=i;
		hash++;
		}
		
		if(dif[i]==-1)
		{
			cout<<-1;
			return 0;
		}
		
			
   }
   
				
		for(i=count;i<len;i++)
		{
			if((dif[i]-dif[len-1])==-1)
			{
				cout<<-1;
				return 0;
			}
	    }
	    
		
		for(i=0;i<hash-1;i++)
		{
			cout<<1<<endl;
		}
		
		cout<<dif[len-1]+1;
		
		return 0;
}
