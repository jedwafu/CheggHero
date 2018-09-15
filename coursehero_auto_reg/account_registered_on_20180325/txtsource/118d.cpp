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
const ll mod = 1e8;
const int N = 1e5+10; 

ll dp[110][110][2];
int k1,k2;
ll DP(int n1,int n2,int p)
{
	if(dp[n1][n2][p]+1)
		return dp[n1][n2][p];

	dp[n1][n2][p]=0;

	if(p)
	FOR(i,1,min(n2,k2))
       dp[n1][n2][1]=(dp[n1][n2][1]+DP(n1,n2-i,0))%mod;
    else
    FOR(i,1,min(n1,k1))
        dp[n1][n2][0]=(dp[n1][n2][0]+DP(n1-i,n2,1))%mod;

    //cout<<n1<<" "<<n2<<" "<<p<<" "<<dp[n1][n2][p]<<endl;
    return dp[n1][n2][p];
}

int main(){
  fast;
  int n1,n2;
  cin>>n1>>n2>>k1>>k2;
  
  fill(dp,-1);
  FOR(i,1,max(n1,n2))
  dp[i][0][1]=dp[0][i][0]=0;

  dp[0][0][0]=dp[0][0][1]=1;
  dp[1][0][0]=1;
  dp[0][1][1]=1;

  cout<<(DP(n1,n2,0)+DP(n1,n2,1))%mod;

  return 0;
}