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

int dp[N][N];
int DP(int n,int m)
{
	if(dp[n][m]!=-1 or dp[m][n]!=-1)
		return dp[n][m];

	if(n==m or n==0 or m==0)
		return dp[n][m]=dp[m][n]=1;

	int sum=1;
	for(int i=1;i<=n;i++)
	sum=min(sum,DP(n-i,m));
	for(int i=1;i<=m;i++)
	sum=min(sum,DP(n,m-i));
	for(int i=1;i<=min(m,n);i++)
	sum=min(sum,DP(n-i,m-i));
	
	if(sum==0)
	dp[m][n]=dp[n][m]=1;
	else
	dp[m][n]=dp[n][m]=0;
	
	return dp[n][m];
}

int main(){
  fast;
  fill(dp,-1);
  dp[0][0]=0;
  
  for(int i=1;i<=1000;i++)
  for(int j=1;j<=i;j++)
  	if(DP(i,j)==0)
  cout<<i<<" "<<j<<endl;
  return 0;
}