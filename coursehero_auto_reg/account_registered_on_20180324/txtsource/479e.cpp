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
const int N = 5e3+10; 

ll dp[N];
ll sums[N];
void prefix(int n)
{
	sums[0]=0;
	sums[1]=dp[1];
	FOR(i,1,n)
	{
		sums[i]=sums[i-1]+dp[i];
		sums[i]%=mod;
		if(sums[i]<0)
			sums[i]+=mod;
	}
}

int main(){
  fast;
  int n,a,b,k;
  cin>>n>>a>>b>>k;
  
  
  FOR(i,1,n)
  sums[i]=i;

  FOR(j,1,k)
  {
  	fill(dp,0);
  	FOR(i,1,n)
  	{
  		if(i==b)
  			continue;
  		int lo,hi;
  	
  		if(b<i)
  		{
  			lo=b+1;
  			hi=min(n,i+i-b-1);
  		}
  		else
  		{
  			hi=b-1;
  			lo=max(1,2*i-b+1);
  		}
  		dp[i]=sums[hi]-sums[lo-1]-sums[i]+sums[i-1];
  		dp[i]%=mod;
  		if(dp[i]<0)
  			dp[i]+=mod;
  	}
  	prefix(n);
  }

  cout<<dp[a];
  return 0;
}