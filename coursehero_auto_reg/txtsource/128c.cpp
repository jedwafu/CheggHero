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

ll ncr[N][N];
int main(){
  fast;
  int n,m,k;
  cin>>n>>m>>k;
  ncr[0][0]=1;

  FOR(i,1,1000)
  FOR(j,0,1000)
  {
  	if(i<j)
  	ncr[i][j]=0;
  	else
  	ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;

  	if(ncr[i][j]<0)
  		ncr[i][j]+=mod;
  }

  if(n-1<2*k or m-1<2*k)
  {
  	cout<<0;
  	return 0;
  }

  ll ans=ncr[n-1][2*k]*ncr[m-1][2*k];
  ans%=mod;
  if(ans<0)
  	ans+=mod;
  cout<<ans;
  return 0;
}