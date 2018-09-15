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
const int N = 3e5+10; 

vector<ii> edges[N];
int done[N];
int ans[N];
int weight[N];
int mini[N];
int maxi[N];
void dfs(int source)
{
	FOR(i,0,sz(edges[source])-1)
	{
 		if(done[edges[source][i].S]<10)
		{
			done[edges[source][i].S]++;
			dfs(edges[source][i].F);
		}

		int dummy1=min(weight[edges[source][i].S],mini[edges[source][i].F]);
		int dummy2=max(weight[edges[source][i].S],maxi[edges[source][i].F]);
		ans[source]=max(ans[source],ans[edges[source][i].F]);
		ans[source]=max(ans[source],weight[edges[source][i].S]-mini[edges[source][i].F]);
		ans[source]=max(ans[source],maxi[edges[source][i].F]-weight[edges[source][i].S]);
		mini[source]=min(mini[source],dummy1);
		maxi[source]=max(maxi[source],dummy2);				
	}
}

int main(){
  fast;
  int n,m;
  cin>>n>>m;
  fill(done,0);
  fill(ans,0);

  FOR(i,1,n)
  {
  	mini[i]=(int)1e9;
  	maxi[i]=0;
  }

  FOR(i,1,m)
  {
  	int u,v,w;
  	cin>>u>>v>>w;
  	edges[u].pb(mp(v,i));
  	weight[i]=w;
  }
  
  FOR(i,1,n)
  {
  	dfs(i);
  }

  int fans=0;
  FOR(i,1,n)
  fans=max(fans,ans[i]);

  cout<<fans;

  return 0;
}