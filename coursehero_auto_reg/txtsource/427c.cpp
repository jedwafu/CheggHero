#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int n,m,temp,num=0,mini=0,ans=0,tnum=1;
vector<int> cost;
vector<int> g[100010];
vector<int> gt[100010];
vector< pair<int,int> > finish;
bool done[100010];

int times=0;

void dfs(int source)
{
	done[source]=true;
	times++;
	for(int i=0;i<g[source].size();i++)
	{
		if(done[g[source][i]]==false)
		{
		   dfs(g[source][i]);
		}
	}
	finish.push_back(make_pair(times,source));
	times++;
	
}

void dfst(int source)
{
	done[source]=true;
	
	for(int i=0;i<gt[source].size();i++)
	{
		
		if(done[gt[source][i]]==false)
		{
		   dfst(gt[source][i]);
		}
    }
		
		if(cost[source-1]==mini)
		num++;
		
		if(cost[source-1]<mini)
		{
			mini=cost[source-1];
			num=1;
		}

}

int main()
{
	long long int a,b;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		done[i+1]=false;
		cin>>temp;
		cost.push_back(temp);
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		gt[b].push_back(a);
	}
	
	for(int i=1;i<=n;i++)
	{
		if(done[i]==false)
		dfs(i);
	}
	
	sort(finish.begin(),finish.end());
	
	for(int i=1;i<=n;i++)
	done[i]=false;
	
	for(int i=n-1;i>=0;i--)
	{
		num=1;
		mini=10000000000;
		if(done[finish[i].second]==false)
		{
			
		  dfst(finish[i].second);
		  ans+=mini;
		  tnum=((tnum%mod)*(num%mod))%mod;
	    }
	}
	
	cout<<ans<<" "<<tnum;
	return 0;
}
