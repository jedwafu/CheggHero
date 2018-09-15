#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
	int t,i;
	char a,b,c,d;
	char ch;
	
	cin>>t;
	while(t--)
	{
		int count=0;
		ch='a';
		while(ch!='\n')
		{
		cin>>a>>b;
		scanf("%c",&ch);
		cin>>c>>d;
		scanf("%c",&ch);
		
		
		if((a==d && b==c)||(a==c && b==d)||(a==b && c==d))
		{
		count++;
	    }
	    
	    }
	    cout<<count<<endl;
	}
	return 0;
}
