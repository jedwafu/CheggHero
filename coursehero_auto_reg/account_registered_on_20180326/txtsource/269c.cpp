#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

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
const int N = 2e5+10; 

vector< pair<int,ii> > edges[N];

bool vis[N];
int flow[N];
int dir[N];
queue<int> Q;
int main(){
  fast;
  int n,m;
  cin>>n>>m;
  fill(flow,0);
  fill(dir,0);
  

  FOR(i,1,m)
  {
  	int u,v,c;
  	cin>>u>>v>>c;
  	fill(vis,0);
  	edges[u].pb(mp(i,mp(v,c)));
  	edges[v].pb(mp(-i,mp(u,c)));
  	flow[u]+=c;
  	flow[v]+=c;
  }

  FOR(i,2,n-1)
  flow[i]/=2;

  
  Q.push(1);
  while(!Q.empty())
  {
  	int ver=Q.front();
  	Q.pop();
  	if(vis[ver])
  		continue;
  	vis[ver]=true;
  	FOR(i,0,sz(edges[ver])-1)
  	{
  		int edgnum=edges[ver][i].F;
  		int to = edges[ver][i].S.F;
  		int fl = edges[ver][i].S.S;
  		if(vis[to])
  			continue;
  		if(edgnum < 0)
  		dir[-edgnum]=1;
  		else
  		dir[edgnum]=0;
  		flow[to]-=fl;
  		if(flow[to]==0)
  			Q.push(to);
  	}

  }

  FOR(i,1,m)
  cout<<dir[i]<<endl;
  return 0;
}