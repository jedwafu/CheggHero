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

int arr[N];
ll dp[N][N];
ll DP(int i,int j)
{
	if(dp[i][j]+1)
		return dp[i][j];

	if(i==j)
		return 0;

	dp[i][j]=(DP(i,j-1)%mod+DP(arr[j-1],j-1)%mod + 2)%mod;
	return dp[i][j];
}
int main(){
  fast;
  int n;
  cin>>n;
  fill(dp,-1);
  FOR(i,1,n)
  cin>>arr[i];

  cout<<DP(1,n+1);
  return 0;
}