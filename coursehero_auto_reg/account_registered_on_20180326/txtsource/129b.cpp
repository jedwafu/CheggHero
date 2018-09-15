#include<bits/stdc++.h>
using namespace std;

int n,m;
int done[101];
bool edges[101][101];
int main()
{
	int a,b,count,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	 done[i]=0;
	 for(int j=1;j<=n;j++)
	 {
	 	edges[i][j]=false;
	 }
    }
    
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		edges[a][b]=true;
		edges[b][a]=true;
		done[a]++;
		done[b]++;
	}
	
	while(m>0)
	{
		for(int i=1;i<=n;i++)
		{
			if(done[i]==0)
		    {
		    	for(int j=1;j<=n;j++)
		    	{
		    		if(edges[i][j]==true)
		    		{
					  done[j]--;
					  edges[i][j]=false;  
					}
				}
			}
	    }
	    
		count=0;
		for(int i=1;i<=n;i++)
		{
			if(done[i]==0)
			continue;
			
			for(int j=i;j<=n;j++)
			{
				if(edges[i][j]==true)
				{
					if(done[i]==1)
					{count++;
					done[i]--;}
					
					if(done[j]==1)
					{count++;
					 done[j]--;
				    }
					
					if(done[i]==1||done[j]==1)
					{
						m--;
					}
				}
			}
		//cout<<i<<" "<<count<<endl;
		}
		if(count>0)
		ans++;
		else
		m=0;
		
	}
	
	cout<<ans;
	return 0;
}
