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

int dp[N];
int temp[N];
vector<ii> wt[N];
int main(){
  fast;
  int n,m;
  cin>>n>>m;
  fill(dp,0);
  fill(temp,0);
  
  FOR(i,1,m)
  {
  	int u,v,w;
  	cin>>u>>v>>w;
  	wt[w].pb(mp(u,v));	
  }

  
  FOR(i,1,N-1)
  {
  	FOR(j,0,sz(wt[i])-1)
  	temp[wt[i][j].S]=max(temp[wt[i][j].S],dp[wt[i][j].F]+1);
  	
  	FOR(j,0,sz(wt[i])-1)
  	{
  		dp[wt[i][j].S]=max(dp[wt[i][j].S],temp[wt[i][j].S]);
  		temp[wt[i][j].S]=0;
  	}

  }

  int ans=1;
  FOR(i,1,n)
  ans=max(ans,dp[i]);
  cout<<ans;
  return 0;
}