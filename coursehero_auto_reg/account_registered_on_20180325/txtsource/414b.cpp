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
ll mods(ll a, ll b)
{
	ll ans= a%b;
	if(ans<0)
		ans+=b;
	return ans;
}

ll dp[2010][2010];

int main(){
  fast;
  int n,k;
  scanf("%d %d",&n,&k);
  
  FOR(i,1,k)
  FOR(j,1,n)
  dp[i][j]=0;

  FOR(i,1,n)
  dp[1][i]=1;
  

  FOR(i,2,k)
  FOR(j,1,n)
  for(int k=j;k<=n;k+=j)
  {
  	dp[i][k]=mods(mods(dp[i-1][j],mod)+mods(dp[i][k],mod),mod);
  }

  ll ans=0;
  FOR(i,1,n)
  ans=mods(mods(ans,mod)+mods(dp[k][i],mod),mod);
  
   printf("%lld",ans);

  return 0;
}