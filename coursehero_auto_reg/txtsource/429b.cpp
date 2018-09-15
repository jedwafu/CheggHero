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

int arr[N][N];
ll dp1[N][N];
ll dp2[N][N];
ll dp3[N][N];
ll dp4[N][N];

int main(){
  fast;
  int n,m;
  cin>>n>>m;

  FOR(i,1,n)
  FOR(j,1,m)
  cin>>arr[i][j];
  
  
  FOR(i,0,n+1)
  FOR(j,0,m+1)
  dp1[i][j]=dp2[i][j]=dp3[i][j]=dp4[i][j]=0;
  
  dp1[1][1]=arr[1][1];
  dp2[n][1]=arr[n][1];
  dp3[1][m]=arr[1][m];
  dp4[n][m]=arr[n][m];

  FOR(i,1,n)
  FOR(j,1,m)
  dp1[i][j]=arr[i][j]+max(dp1[i-1][j],dp1[i][j-1]);
  

  NFOR(i,n,1)
  FOR(j,1,m)
  dp2[i][j]=max(dp2[i][j-1]+arr[i][j],dp2[i+1][j]+arr[i][j]);
  

  FOR(i,1,n)
  NFOR(j,m,1)
  dp3[i][j]=arr[i][j]+max(dp3[i][j+1],dp3[i-1][j]);
  

  NFOR(i,n,1)
  NFOR(j,m,1)
  dp4[i][j]=arr[i][j]+max(dp4[i+1][j],dp4[i][j+1]);
  

  ll ans=0;
  FOR(i,2,n-1)
  FOR(j,2,m-1)
  {
  	ans=max(ans,dp1[i][j-1]+dp2[i+1][j]+dp3[i-1][j]+dp4[i][j+1]);
  	ans=max(ans,dp1[i-1][j]+dp2[i][j-1]+dp3[i][j+1]+dp4[i+1][j]);
  }

  cout<<ans;
  return 0;
}