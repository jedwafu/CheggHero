#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
using namespace std;

int main()
{
	int n,i,j,count=0;
	char str[200000];
	cin>>n;
	scanf("\n");
	gets(str);

	for(i=1;i<2*n-2;i=i+2)
	{
		for(j=0;j<i;j=j+2)
		{
			if(str[j]==tolower(str[i]))
			{
				str[j]='0';
				break;
			}
		
		}
		if(j==i+1)
		count++;
	}
	
	cout<<count;
}
