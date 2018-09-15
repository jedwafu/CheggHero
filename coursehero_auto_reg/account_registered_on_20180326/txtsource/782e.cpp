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
const int N = 2e5+10; 

vi edges[N];
vi eulertour;
bool vis[N];
void dfs(int source,int par)
{
	vis[source]=true;
	eulertour.pb(source);
	FOR(i,0,sz(edges[source])-1)
	{
		if(edges[source][i]==par or vis[edges[source][i]])
			continue;

		dfs(edges[source][i],source);
		eulertour.pb(source);
	}
}
vi ans;
int main(){
  fast;
  int n,m,k;
  cin>>n>>m>>k;

  fill(vis,0);
  
  FOR(i,1,m)
  {
  	int x,y;
  	cin>>x>>y;
  	if(x!=y)
  	{
  		edges[x].pb(y);
  		edges[y].pb(x);
  	}
  }

  dfs(1,0);
  int lim=(((2*n)%k==0) ? (2*n)/k : (2*n)/k +1);
  int cnt=1;
  FOR(i,0,sz(eulertour)-1)
  {
	ans.pb(eulertour[i]);

	if(sz(ans)==lim or i==sz(eulertour)-1)
  	{
  		cout<<sz(ans)<<" ";
  		FOR(j,0,sz(ans)-1)
  		cout<<ans[j]<<" ";
  		cout<<endl;
  		ans.clear();
  		cnt++;
  	}
  }

  FOR(i,cnt,k)
  cout<<1<<" "<<1<<endl;
  
  return 0;
}