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
const ll INF = 1e14;
const ll mod = 1e9+7;
const int N = 5e3+10; 

ll dp[N][N];
ll h[N][N];
ll x[N];
ll w[N];
int main()
{
  fast;
  int n,k;
  cin>>n>>k;
  FOR(i,1,n)
  cin>>x[i]>>w[i];
  dp[0][0]=0;
  FOR(i,1,n)
  {
  	dp[i][0]=INF;
  	FOR(j,1,k)
  	{
  		if(j>i)
  		{
  			dp[i][j]=INF;
  			h[i][j]=-INF;
  		}
  		else
  		{
  			if(i>j)
  			dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]+w[i]*(x[i]-h[i-1][j]));
  			else
  			dp[i][j]=dp[i-1][j-1];
  			
  			//cout<<"dp "<<i<<" "<<j<<" is "<<dp[i][j]<<endl;

  			if(dp[i][j]==dp[i-1][j-1])
  			h[i][j]=x[i];
  			else
  			h[i][j]=h[i-1][j];
  		}
  	}
  }
  
  cout<<dp[n][k];
  return 0;
}