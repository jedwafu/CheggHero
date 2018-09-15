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
const int N = 1e5+10; 

vi edges[N];
ll d[N];
ll sums[N];
ll ans=0;

ll LCM(ll x,ll y)
{
	ll res=x/__gcd(x,y);
	return res*y;
}

void dfs(int source,int par)
{
	ll mini=INF;
	ll lcm=1;
	FOR(i,0,sz(edges[source])-1)
	{
		if(edges[source][i]==par)
			continue;
		dfs(edges[source][i],source);
		mini=min(mini,sums[edges[source][i]]);
		lcm=LCM(lcm,d[edges[source][i]]);
	}
    
    ll x=0;
    if(lcm)
    	x=(mini/lcm)*lcm;
    
    FOR(i,0,sz(edges[source])-1)
	{
		if(edges[source][i]==par)
			continue;
		ans+=(sums[edges[source][i]]-x);
		sums[edges[source][i]]=x;
		sums[source]+=x;
		d[source]+=lcm;
	}

}

int main(){
  fast;
  int n;
  fill(d,0);
  cin>>n;
  FOR(i,1,n)
  cin>>sums[i];

  FOR(i,1,n-1)
  {
  	int x,y;
  	cin>>x>>y;
  	edges[x].pb(y);
  	edges[y].pb(x);
  }

  FOR(i,2,n)
  if(sz(edges[i])==1)
  d[i]=1;

  dfs(1,0);

  cout<<ans<<endl;
  return 0;
}