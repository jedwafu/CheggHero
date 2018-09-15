#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
	long long int a,b;
	cin>>a>>b;
	
	if(a<b)
	{
		cout<<0;
		return 0;
	}
	
	if(a==b)
	{
		cout<<"infinity";
		return 0;
	}
	
	int dif=a-b;
	int count=0;
	
	for(int i=1;i<sqrt(dif);i++)
	{
		   if(dif%i==0)
		   {
		   	if(i<=b)
	        {
	          if(dif/i>b)
	          count++;
   				
			}	
		   	
		   	else
		   	count=count+2;
		   	
		   }	
		
	}
	
	int n=sqrt(dif);
	if(n*n==dif && sqrt(dif)>b)
	count++;
	
	cout<<count;
	
	return 0;

}
