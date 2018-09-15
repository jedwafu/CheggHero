#include<bits/stdc++.h>
using namespace std;
int n;
bool matrix[3001][3001];
int dis[3001];
bool found[3001];
stack<int> cycle;

int dfs(int source,int prev)
{
	found[source]=true;
	cycle.push(source);
	for(int i=1;i<=n;i++)
	{
		if(matrix[source][i]==true && i!=prev)
		{
			if(found[i]==true)
			{
			   return i;	
				
			}
			else
			{
				int vals=dfs(i,source);
				if(vals)
				return vals;
			}
		}
	}
	
	cycle.pop();
	return 0;
}

void dfs2(int source)
{
	found[source]=true;
	for(int i=1;i<=n;i++)
	{
		if(matrix[source][i]==true && found[i]==false)
		{
			dis[i]=dis[source]+1;
			dfs2(i);
		}
	}
}

int main()
{
	cin>>n;
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		matrix[i][j]=false;
	}
	
	for(int i=0;i<n;i++)
	{
		found[i+1]=false;
		dis[i+1]=-1;
		int a,b;
		cin>>a>>b;
		matrix[a][b]=matrix[b][a]=true;
	}
	int val=dfs(1,1);
	
	cur=cycle.top();
	matrix[cur][val]=matrix[val][cur]=false;
	dis[val]=0;
	
	while(cur!=val)
	{
		cycle.pop();
		dis[cur]=0;
		matrix[cur][cycle.top()]=false;
		matrix[cycle.top()][cur]=false;
		cur=cycle.top();
	}
	
	for(int i=1;i<=n;i++)
	found[i]=false;
	
	for(int i=1;i<=n;i++)
	{
		if(found[i]==false && dis[i]==0)
		dfs2(i);
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<dis[i]<<" ";
	}
	
	return 0;
}
