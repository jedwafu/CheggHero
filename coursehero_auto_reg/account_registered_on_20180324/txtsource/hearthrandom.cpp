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
const int N = 1e6+10; 

ll dp[N];
ll ansfor[N];
ll pows[N];
int main(){

  fast;
  int t;
  fill(dp,0);
  cin>>t;

  pows[0]=1;
  FOR(i,1,N-1)
  pows[i]=(2*pows[i-1])%mod;

  dp[1]=1;
  dp[2]=2;
  ll oddsums=1;
  ll evensums=2;
  FOR(i,3,N-1)
  {
  	if(i%2)
  	{
  		dp[i]=evensums+1;
  		oddsums=(oddsums+dp[i])%mod;
  	}
  	else
  	{
  		dp[i]=oddsums+1;
  		evensums=(evensums+dp[i])%mod;
  	}
  }

  FOR(i,1,N-1)
  {
  	ansfor[i]=(ansfor[i-1]+dp[i]-1)%mod;
  	if(ansfor[i]<0)
  		ansfor[i]+=mod;
  }

  FOR(i,1,N-1)
  {
  	ansfor[i]=(pows[i]-ansfor[i])%mod;
  	if(ansfor[i]<0)
  		ansfor[i]+=mod;
  }

  while(t--)
  {
  	int n;
  	cin>>n;
  	cout<<ansfor[n]<<endl;
  }

  return 0;
}