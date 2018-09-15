#include<bits/stdc++.h>
using namespace std;

int pows[24];
int main()
{
	pows[0]=1;
	for(int i=1;i<24;i++)
	{
		pows[i]=2*pows[i-1];
	}
	
	int t,a,b,count,ind;
	bool flag;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		count=0;
		flag=true;
		for(int i=0;i<24;i++)
		{
			if(b==pows[i])
			ind=i;
		}
		
		while(flag)
		{
			for(int i=0;i<24;i++)
			{
				if(a==pows[i])
				{
					if(i==ind)
					cout<<count<<endl;
					else
					cout<<count+abs(i-ind)<<endl;
					
					flag=false;
				}
		    }
		    
			
			
				if(a%2==0)
				a=a/2;
				else
				a=(a-1)/2;
					
				count++;
		    
		}
		
	}
	return 0;
}
