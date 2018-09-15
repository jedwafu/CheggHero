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
const int mod = 1e9+7;
const int N = 90; 

vector<ii> edges[N];
int dp[2][N][N][N];
int DP(int st,int l,int r,int gft)
{
	if(gft==0)
		return 0;
	if(l==r)
		return mod;

	if(dp[st][l][r][gft]!=-1)
		return dp[st][l][r][gft];

	cout<<"called for "<<st<<" "<<l<<" "<<r<<" "<<gft<<endl;
	dp[st][l][r][gft]=mod;
	if(st==0)
	{
		FOR(i,0,sz(edges[l])-1)
		{
		if(edges[l][i].F>l and edges[l][i].F<=r)
		{
			dp[st][l][r][gft]=min(dp[st][l][r][gft],edges[l][i].S+min(DP(0,edges[l][i].F,r,gft-1),DP(1,l,edges[l][i].F,gft-1)));
		}
		}
		return dp[st][l][r][gft];
	}
	else
	{
		FOR(i,0,sz(edges[r])-1)
		{
		if(edges[r][i].F>l and edges[r][i].F<r)
		{
			dp[st][l][r][gft]=min(dp[st][l][r][gft],edges[r][i].S+min(DP(0,edges[l][i].F,r,gft-1),DP(1,l,edges[l][i].F,gft-1)));
		}
		}
		return dp[st][l][r][gft];	
	}
}

int main(){
  fast;
  int n,k,m;
  cin>>n>>k>>m;
  fill(dp,-1);
  FOR(i,1,m)
  {
  	int u,v,c;
  	cin>>u>>v>>c;
  	edges[u].pb(mp(v,c));
  }

  int ans=mod;
  FOR(i,1,n)
  {
  	FOR(j,0,sz(edges[i])-1)
  	{
  		if(i==edges[i][j].F)
  			continue;
  		if(i>edges[i][j].F)
  		ans=min(ans,DP(1,edges[i][j].F,i,k-1));
  		else
  		ans=min(ans,DP(0,i,edges[i][j].F,k-1));
  	}
  }
  cout<<ans;
  return 0;
}