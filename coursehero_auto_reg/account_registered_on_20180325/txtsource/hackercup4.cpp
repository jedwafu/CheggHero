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

vector<ll> C[400];

ll sums[400][400];
ll dp[400][400];
int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);	
  fast;
  int t;
  cin>>t;
  FOR(T,1,t)
  {
  	int n,m;
  	cin>>n>>m;
  	FOR(i,0,399)
  	FOR(j,0,399)
  	dp[i][j]=INF;

  	FOR(i,0,n-1)
  	{
  		C[i].clear();
  		FOR(j,0,m-1)
  		{
  			ll temp;
  			cin>>temp;
  			C[i].pb(temp);
  		}
  		sort(C[i].begin(),C[i].end());
  		sums[i][0]=C[i][0];
  		FOR(j,1,m-1)
  		sums[i][j]=sums[i][j-1]+C[i][j];
  	}

  	dp[0][0]=0;

  	FOR(i,1,m)
  	{
  		dp[0][i]=sums[0][i-1]+(i*i);
  	}

  	FOR(i,1,n-1)
  	{
  		FOR(j,1,n)
  		{
  			FOR(k,1,j)
  			if(j-k>=0 and j-k<m)
  			dp[i][j]=min(dp[i][j],dp[i-1][k]+sums[i][j-k]+(((ll)j-(ll)k+(ll)1)*((ll)j-(ll)k+(ll)1)));

  			dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
  		}
  	}

  	cout<<"Case #"<<T<<": "<<dp[n-1][1]<<endl;
  }
  return 0;
}