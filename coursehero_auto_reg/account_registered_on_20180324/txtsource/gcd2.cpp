#include<bits/stdc++.h>
using namespace std;

int hcf(int a,int b)
{
	if(b==0)
	return a;
	else
	return hcf(b,a%b);
}

char arr[300];
int main()
{
	int t,d,newb,i;
	cin>>t;
	while(t--)
	{
		cin>>d;
		scanf("%s",arr);
		
		int len=strlen(arr);
		newb=0;
		
		if(d==0)
		{
			printf("%s\n",arr);
			
		}
		else
		{
		
		for(i=0;i<len;i++)
		{
			newb=(10*newb +(arr[i]-'0'))%d;
		}
		
		printf("%d\n",hcf(d,newb));
	    }
	}
	return 0;
}
