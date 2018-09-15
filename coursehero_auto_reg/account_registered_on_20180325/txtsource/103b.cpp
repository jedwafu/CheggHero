#include<bits/stdc++.h>
using namespace std;

int n,m;
bool done[101];
bool edges[101][101];

void dfs(int source)
{
	for(int j=1;j<=n;j++)
	{
		done[source]=true;
		if(edges[source][j]==true && done[j]==false)
		{
			done[j]=true;
			dfs(j);
		}
	}
}

int main()
{
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		done[i]=false;
		for(int j=1;j<=n;j++)
		edges[i][j]=false;
	}
	
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		edges[x][y]=true;
		edges[y][x]=true;
	}
	
	if(n!=m)
    {
    	cout<<"NO";
    	return 0;
	}
	
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		if(done[i]==false)
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"FHTAGN!";
	return 0;
}
