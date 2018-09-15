#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e6+10; 

vi edges[N];
bool vis[N];
bool self[N];
void dfs(int source)
{
	vis[source]=true;
	FOR(i,0,sz(edges[source])-1)
	{
		if(!vis[edges[source][i]])
			dfs(edges[source][i]);
	}
}

int main(){
  fast;
  ll n,m;
  cin>>n>>m;
  fill(vis,0);
  fill(self,0);
  
  FOR(i,1,n)
  edges[i].clear();

  ll cnt=0;
  int root;
  FOR(i,1,m)
  {
  	int u,v;
  	cin>>u>>v;
  	root=u;
  	edges[u].pb(v);
  	if(u!=v)
  	edges[v].pb(u);
  	else
  	{
  		self[u]=true;
  		cnt++;
  	}
  }

  dfs(root);
  FOR(i,1,n)
  if(sz(edges[i]) and !vis[i])
  {
  	cout<<0<<endl;
  	return 0;
  }

  ll ans=0;
  FOR(i,1,n)
  {
  	if(self[i]==false)
  	ans+=max((ll)0,(1LL*sz(edges[i])*(sz(edges[i])-1))/2);
  	else
  	ans+=max((ll)0,(1LL*(sz(edges[i])-1)*(sz(edges[i])-2))/2);
  }

  ans+=cnt*(m-cnt)+(cnt*(cnt-1))/2;
  cout<<ans;
  return 0;
}