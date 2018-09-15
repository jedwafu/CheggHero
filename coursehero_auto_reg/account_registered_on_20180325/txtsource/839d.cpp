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

ll cnt[N];
ll pwr[N],final[N];

int main()
{
  fast;

  pwr[0]=1;
  FOR(i,1,N-1)
  {
  	cnt[i]=0;
  	final[i]=0;
  	pwr[i]=(pwr[i-1]*2)%mod;
  	if(pwr[i]<0)
  		pwr[i]+=mod;
  }
  
  int n;
  cin>>n;
  FOR(i,1,n)
  {
  	ll temp;
  	cin>>temp;
  	cnt[temp]++;
  }

  FOR(i,2,N-1)
  {
  	for(int j=2*i;j<N;j+=i)
  		cnt[i]+=cnt[j];
  }

  ll ans=0;
  NFOR(i,N-1,2)
  {
  	if(cnt[i]==0)
  		continue;

  	final[i]=(cnt[i]*pwr[cnt[i]-1])%mod;
  	if(final[i]<0)
  		final[i]+=mod;

  	for(int j=2*i;j<N;j+=i)
  	{
  			final[i]-=final[j];
  			if(final[i]<0)
  			final[i]+=mod;
  	}	
  	

  	ans+=(i*final[i])%mod;
  	ans%=mod;
  	if(ans<0)
  		ans+=mod;
  	
  	if(ans<0)
  		ans+=mod;
  }

  cout<<ans;
  return 0;
}