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

int v[N],c[N];
ll dp[N];
ll maxi,maxi2;
int main()
{
  fast;
  int n,q;
  cin>>n>>q;
  
  FOR(i,1,n)
  cin>>v[i];
  FOR(i,1,n)
  cin>>c[i];

  FOR(k,1,q)
  {
  	ll a,b;
  	cin>>a>>b;
  	FOR(i,1,n)
  	dp[i]=-INF;

  	dp[c[1]]=max(dp[c[1]],b*v[1]);
  	maxi=dp[c[1]];
  	maxi2=-INF;
  	FOR(i,2,n)
  	{
  		if(maxi==dp[c[i]])
  		{
  			dp[c[i]]=max(dp[c[i]],dp[c[i]]+a*v[i]);
  			dp[c[i]]=max(dp[c[i]],maxi2+b*v[i]);
  			dp[c[i]]=max(dp[c[i]],b*v[i]);
  			maxi=dp[c[i]];
  		}	
  		else
  		{
  			dp[c[i]]=max(dp[c[i]],dp[c[i]]+a*v[i]);
  			dp[c[i]]=max(dp[c[i]],maxi+b*v[i]);
  			dp[c[i]]=max(dp[c[i]],b*v[i]);
  			if(dp[c[i]]>maxi)
  			{
  				maxi2=maxi;
  				maxi=dp[c[i]];
  			}
  			else if(dp[c[i]]>maxi2)
  			{
  				maxi2=dp[c[i]];
  			}
  		}
  	}

  	ll ans=0;
  	FOR(i,1,n)
  	ans=max(ans,dp[i]);
  	cout<<ans<<endl;

  }

  return 0;
}