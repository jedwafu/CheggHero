#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int ispalindrome(char *arr,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arr[i]!=arr[size-1-i])
		return 0;
	}
	return 1;
}
int main()
{
	char str[1001];
	char copy[1001];
	int k,flag=1;
	int i=0,j=0;
	gets(str);
	cin>>k;
	int len=strlen(str);
	if(len%k!=0)
	{
	 cout<<"NO";
	 return 0;
    }
    
    else
    {
    	k=len/k;
    	while(i<len)
    	{
    		for(j=0;j<k;j++)
    		{
			  copy[j]=str[i];
    		  i++;
    	    }
    		
    	 flag=ispalindrome(copy,k);
    	 if(flag==0)
    	 {
    	 	cout<<"NO";
    	 	return 0;
		 }
    	 
		}
	   cout<<"YES";
	}
	return 0;
}
