#include<bits/stdc++.h>
using namespace std;

bool can(int m,int s)
{
	return (s>=0 and s<=9*m);
}
int main()
{
	int m,s;
	cin>>m>>s;

    int sum=s;

    string mini;
    string maxi;
    bool flag=true;
    
    if(m==1 and s==0)
    {
    	cout<<0<<" "<<0;
    	return 0;
    }
    
    for(int d=1;d<10;d++)
    {
    	if(can(m-1,sum-d))
    	{
    		mini+=char('0'+d);
    		sum-=d;
    		break;
    	}

    	if(d==9)
    		flag=false;
    }
    
    if(!flag)
    {
    	cout<<-1<<" "<<-1<<endl;
    	return 0;
    }	
 
	for(int i=2;i<=m;i++)
	{
		for(int d=0;d<10;d++)
		{
            if(can(m-i,sum-d))
            {
            	mini+=char('0'+d);
            	sum-=d;
            	break;
            }
		}
	}
    sum=s;
	for(int d=9;d>0;d--)
    {
    	if(can(m-1,sum-d))
    	{
    		maxi+=char('0'+d);
    		sum-=d;
    		break;
    	}
    }
 
	for(int i=2;i<=m;i++)
	{
		for(int d=9;d>=0;d--)
		{
            if(can(m-i,sum-d))
            {
            	maxi+=char('0'+d);
            	sum-=d;
            	break;
            }
		}
	}

	cout<<mini<<" "<<maxi<<endl;
	return 0;

}