#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
	int t,i;
	char s[110],ch;
	cin>>t;
	ch=getchar();
	while(t--)
	{
		
		gets(s);
		//cout<<s<<endl;
		int len=strlen(s);
		int flag=1;
		
		if((len==2 && s[0]==s[1])|| s[0]==s[1])
		{flag=0;
		cout<<"NO\n";
	    }
		else
		{
			
		
		   for(i=0;i<len-2;i++)
		   {
			if(s[i]!=s[i+2])
			{
			cout<<"NO\n";
		    flag=0;
		    break;
		    }
		    
		   }
		   	   
	    }
	    if(flag==1)
	       cout<<"YES\n";
    }
	return 0;
}
