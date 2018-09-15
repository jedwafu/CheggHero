#include<bits/stdc++.h>
using namespace std;
#define tr(container,it) for( typeof(m.begin()) it = container.begin(); it != container.end(); it++)
char colors[][7]={"black","blue","red","green","orange","yellow"};
char inp[6][7];
int arr[6];
int ans;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ans=7;
		for(int i=0;i<6;i++)
		arr[i]=0;
		
		for(int i=0;i<6;i++)
        {       
			cin>>inp[i];
			for(int j=0;j<6;j++)
			{
				if(!strcmp(colors[j],inp[i]))
				{
					arr[j]++;
					break;
				}
			}	
		}
		 
		for(int i=0;i<6;i++)
		{
			if(arr[i]>=3)
			ans=i;
		}
		
		int flag1=0,flag2=0,flag3=0;
		
		if(ans!=7)
		{
				
		if(!strcmp(inp[0],colors[ans])|| !strcmp(inp[1],colors[ans]))
		flag1=1;
		
		if(!strcmp(inp[2],colors[ans])|| !strcmp(inp[3],colors[ans]))
		flag2=1;
		
		if(!strcmp(inp[4],colors[ans])|| !strcmp(inp[5],colors[ans]))
		flag3=1;
	    }
			
		if(flag1 && flag2 && flag3)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	
	return 0;
	
}
