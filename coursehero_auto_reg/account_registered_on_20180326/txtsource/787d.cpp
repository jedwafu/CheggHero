#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,ll> ii;
typedef pair<ll,int> pli;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e5+10; 

vector<ii> edges[9*N];
ll dist[9*N];
int ver[2][4*N];
int t;
priority_queue <pli, vector<pli>, greater<pli> > Q; 
int counter;

void build(int curr,int l,int r){
	ver[t][curr]=counter;
	counter++;

  if(l == r){

  	if(!t)
  	edges[ver[t][curr]].pb(mp(l,0));
  	else
  	edges[l].pb(mp(ver[t][curr],0));
  	
    return;
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  build(c1,l,mid);
  build(c2,mid+1,r);
  
  if(!t)
  {
  	edges[ver[t][curr]].pb(mp(ver[t][c1],0));
  	edges[ver[t][curr]].pb(mp(ver[t][c2],0));
  }
  else	
  {
  	edges[ver[t][c1]].pb(mp(ver[t][curr],0));
  	edges[ver[t][c2]].pb(mp(ver[t][curr],0));
  }
}

void query2(int curr,int l,int r,int x,int y,int v,ll w){
  if(l > y || r < x)return ;
  if(x <= l && r <= y){
    edges[v].pb(mp(ver[0][curr],w));
    return;
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  query2(c1,l,mid,x,y,v,w);
  query2(c2,mid+1,r,x,y,v,w);
  return;
}

void query3(int curr,int l,int r,int x,int y,int v,ll w){
  if(l > y || r < x)return ;
  if(x <= l && r <= y){
  	//cout<<l<<" "<<r<<endl;
    edges[ver[1][curr]].pb(mp(v,w));
    return;
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  query3(c1,l,mid,x,y,v,w);
  query3(c2,mid+1,r,x,y,v,w);
  return;
}


void Dijsktra(int source)
{
	FOR(i,1,9*N-1)
	dist[i]=INF;

	dist[source]=0;

	Q.push(mp(0,source));
	while(!Q.empty())
	{
		ll dis=Q.top().F;
		int vertex=Q.top().S;
		Q.pop();

		if(dist[vertex]!=dis)
			continue;

		FOR(i,0,sz(edges[vertex])-1)
		{
			if(dist[edges[vertex][i].F]>dis+edges[vertex][i].S)
			{
				dist[edges[vertex][i].F]=dis+edges[vertex][i].S;
				Q.push(mp(dist[edges[vertex][i].F],edges[vertex][i].F));
			}
		}	
	}
}

int main(){
  fast;
  int n,q,s;
  cin>>n>>q>>s;
  counter=n+1;
  t=0;
  build(1,1,n);
  t=1;
  build(1,1,n);

  FOR(i,1,q)
  {
  	int t,u,v,l,r;
  	ll w;
  	cin>>t;
  	if(t==1)
  	{
  		cin>>u>>v>>w;
  		edges[u].pb(mp(v,w));
  	}
  	if(t==2)
  	{
  		cin>>v>>l>>r>>w;
  		query2(1,1,n,l,r,v,w);
  	}
  	if(t==3)
  	{
  		cin>>v>>l>>r>>w;
  		query3(1,1,n,l,r,v,w);
  	}
  }

  Dijsktra(s);

  FOR(i,1,n)
  {
  	if(dist[i]==INF)
  		dist[i]=-1;
  	cout<<dist[i]<<" ";
  }
  return 0;
}