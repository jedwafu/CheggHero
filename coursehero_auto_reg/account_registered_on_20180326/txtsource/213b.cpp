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

int a[20];
ll choose[110][110];
ll dp[110][20];

int main(){
  fast;
  int n;
  fill(dp,0);
  cin>>n;
  FOR(i,0,9)
  cin>>a[i];

  FOR(i,0,105)
  FOR(j,0,105)
  {
  	if(i<j)
  		choose[i][j]=0;
  	else if(i==j or j==0)
  		choose[i][j]=1;
  	else
  		choose[i][j]=(choose[i-1][j-1]+choose[i-1][j])%mod;
  }

  FOR(i,0,n)
  if(i>=a[9])
  	dp[i][9]=1;

 NFOR(j,8,1)
 {
 	FOR(i,0,n)
 	{
 		FOR(k,a[j],i)
 		dp[i][j]=(dp[i][j]+(dp[i-k][j+1]*choose[i][k])%mod)%mod;
 	}
 }

 FOR(i,0,n)
 {
 	FOR(k,a[0],i)
 	{
 		dp[i][0]=(dp[i][0]+(dp[i-k][1]*choose[i-1][k])%mod)%mod;
 	}
 }

 ll ans=0;
 FOR(i,0,n)
 ans=(ans+dp[i][0])%mod;

 if(ans<0)
 	ans+=mod;

 cout<<ans;
  return 0;
}