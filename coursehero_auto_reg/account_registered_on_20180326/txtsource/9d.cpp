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

ll dp[40][40];

ll solve(int n,int h)
{
	//cout<<"called for "<<n<<" "<<h<<endl;
	if(n<h)
		return 0;

	if(dp[n][h]+1)
		return dp[n][h];

	dp[n][h]=0;
	FOR(i,0,n-1)
	{
		ll temp=solve(i,h-1);
		ll temp2=0;
		FOR(j,0,h-1)
		temp2+=solve(n-i-1,j);
		
		dp[n][h]+=temp*temp2;
	}

	FOR(i,0,n-1)
	{
		ll temp=solve(i,h-1);
		ll temp2=0;
		FOR(j,0,h-2)
		temp2+=solve(n-i-1,j);
		
		dp[n][h]+=temp*temp2;
	}

	//cout<<"dp "<<n<<" "<<h<<" "<<dp[n][h]<<endl;
	return dp[n][h];
}

int main(){
  fast;
  int n,h;
  cin>>n>>h;

  fill(dp,-1);
  
  dp[0][0]=1;
  FOR(i,1,n)
  dp[i][0]=0;

  ll ans=0;
  FOR(i,h,n)
  ans+=solve(n,i);

  cout<<ans;
  return 0;
}