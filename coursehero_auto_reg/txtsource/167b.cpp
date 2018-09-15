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

double dp[210][210][210];
double p[210];
int a[210];

int main()
{
  
  fast;
  int n,l,K;
  fill(dp,0);
  
  cin>>n>>l>>K;
  K=min(K,n);

  dp[1][0][0]=1.0;

  FOR(i,1,n)
  cin>>p[i];

  FOR(i,1,n)
  cin>>a[i];
  
  FOR(i,1,n)
  FOR(j,0,i)
  FOR(k,0,n)
  {
  	int c=a[i]+1;
  	dp[i+1][j+1][min(k+c,n)]+=dp[i][j][k]*((p[i])/100);
  	dp[i+1][j][k]+=dp[i][j][k]*((100-p[i])/100);
  }

  double ans=0.0;
  FOR(i,l,n)
  FOR(j,0,n)
  {
  	if(K+j-i>=0)
  		ans+=dp[n+1][i][j];
  }
  cout<<setprecision(12);
  cout<<ans<<endl;
  return 0;
}