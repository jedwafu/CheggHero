#include <bits/stdc++.h>
using namespace std;

#define INF 1e16

typedef long long ll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef map<string, int> msi;

#define all(x) x.begin(), x.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define spresent(c,x) ((c).find(x) != (c).end())  // for set,map
#define present(c,x) (find(all(c),x) != (c).end())  // for vector
#define F first
#define S second
#define loop(i,a,b) for(int i=int(a);i<=int(b);++i)
#define nloop(i,a,b) for(int i= int(a);i>=int(b);--i)


vii edges[500010];
ll dis[400010];
int par[400010];
int w[400010];
int n,m,k;
priority_queue<ii> q_dij;
int trains=0;

void dijkstra(int source)
{
	dis[source]=0;
	
	q_dij.push(mp(dis[source],source));
	
	while(q_dij.empty()==false)
	{
		
		int s=q_dij.top().S;
		
		if(-q_dij.top().F>dis[s])
		{
			q_dij.pop();
			continue;
		}
		    
		q_dij.pop();
	    
	    
		loop(i,0,sz(edges[s])-1)
		{
			if(dis[edges[s][i].F]>dis[s]+w[edges[s][i].S])
			{
				dis[edges[s][i].F]=dis[s]+w[edges[s][i].S];
				par[edges[s][i].F]=edges[s][i].S;			
				q_dij.push(mp(-dis[edges[s][i].F],edges[s][i].F));
			}
			
			else if(dis[edges[s][i].F]==dis[s]+w[edges[s][i].S] && edges[s][i].S<=m)
			{
				par[edges[s][i].F]=edges[s][i].S;
			}
		}
	}
}

int main()
{
	
	cin>>n>>m>>k;
	loop(i,1,n) dis[i]=INF,par[i]=0;
	
	loop(i,1,m)
	{
		ll u,v,x;
		scanf("%I64d %I64d %I64d",&u,&v,&x);
		edges[u].pb(mp(v,i));
		edges[v].pb(mp(u,i));
		w[i]=x;
	}
	
    loop(i,1,k)
    {
    	ll s,y;
    	scanf("%I64d %I64d",&s,&y);
        edges[1].pb(mp(s,i+m));
        w[i+m]=y;
	}
	
	dijkstra(1);
	loop(i,1,n)
	{
		if(par[i]>m)
		trains++;
	}
	cout<<k-trains;
}
