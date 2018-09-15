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
const int N = 1e3+10; 

int p[N];
int dp[N][N];
vi help;
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	int n,m;
  	cin>>n>>m;
  	FOR(i,1,n)
  	cin>>p[i];

  	FOR(i,1,n)
  	dp[i][0]=0;

  	FOR(i,1,n)
  	FOR(j,1,i-1)
  	{
  		if(p[j]<p[i])
  			dp[i][j]=dp[i][j-1]+1;
  		else
  			dp[i][j]=dp[i][j-1];
  	}

  	ll ans=1;
  	FOR(j,1,m)
  	{
  		ans=1;
  		help.clear();
  		int l1,r1,l2,r2;
  		cin>>l1>>r1>>l2>>r2;
  		FOR(i,l2,r2)
  		help.pb(dp[i][r1]-dp[i][l1-1]);
  		
  		sort(help.begin(),help.end());
  		FOR(i,0,sz(help)-1)
  		{
  			ans=(ans*(help[i]-i))%mod;
  			if(ans<0)
  				ans+=mod;
  		}

  		cout<<ans<<endl;
  	}
  }
  return 0;
}