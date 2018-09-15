#include<bits/stdc++.h>
using namespace std;

bool graph[1010][1010];
int colors[1010];
bool visited[1010];
queue<int> q;
int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t,n,m,a,b;
	cin>>t;
	while(t--)
	{
       cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		graph[i][j]=true;

    for(int i=1;i<=n;i++)
    	{ 
    		colors[i]=-1;
    		visited[i]=false;
    	}

	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		graph[a][b]=false;
		graph[b][a]=false;
	} 
    
    
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
    	while(!q.empty())
    		q.pop();

    	if(visited[i]==false)
    	{
    		colors[i]=1; 
    		q.push(i);
    		visited[i]=true;

    		while(!q.empty())
    		{
    			int u=q.front();
    			q.pop();

    			for(int v=1;v<=n;v++)
    			{
    				if(graph[u][v] and colors[v]==-1 and u!=v)
    				{
    					colors[v]=1-colors[u];
    					q.push(v);
    					visited[v]=true;
    				}
    				else if(graph[u][v] and colors[v]==colors[u] and u!=v)
    				{
    					flag=false;
    					break;
    				}
    				if(!flag)
    					break;
    			}
    			if(!flag)
    				break;
    		}

    	}
    	if(!flag)
    		break;
    }

    if(flag)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;       
    }
    return 0;
}