#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair< pair<int,int>,int> > edges;
int dp[101][101];
bool done[101];
queue<int> q;

void bfs(int source,int color)
{
	done[source]=1;
	q.push(source);
	while(q.empty()==false)
	{
		int top=q.front();
		q.pop();
		for(int i=0;i<m;i++)
		{
			if(edges[i].second==color && edges[i].first.first==top && done[edges[i].first.second]==false)
			{
			done[edges[i].first.second]=true;
			q.push(edges[i].first.second);}
			else if(edges[i].second==color && edges[i].first.second==top && done[edges[i].first.first]==false)
			{
				done[edges[i].first.first]=true;
			    q.push(edges[i].first.first);
			}
		}
	}
}

int main()
{
	int a,b,c,q;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		edges.push_back(make_pair(make_pair(a,b),c));
	}
	cin>>q;
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	dp[i][j]=0;
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			done[k]=false;
			
			bfs(j,i);
			for(int k=1;k<=n;k++)
			if(done[k]==true)
			dp[j][k]++;
		}
	}
	
	for(int i=0;i<q;i++)
	{
		cin>>a>>b;
		cout<<dp[a][b]<<endl;
		
   }
   return 0;
	
}
