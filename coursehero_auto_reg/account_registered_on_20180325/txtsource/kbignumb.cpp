#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e5+10; 

ii fast_exp(ll base,ll exp,ll MOD)
{
	if(exp==1)
	{
		ll ret1=(base*base)%MOD;
		if(ret1<0)
			ret1+=MOD;

		ll ret2=(1+base)%MOD;
		if(ret2<0)
			ret2+=MOD;

		return mp(ret1,ret2);
	}

	if(exp%2)
	{
		ii val=fast_exp(base,exp/2,MOD);
		ll f=val.F;
		ll s=val.S;

		ll ret1=(f*f)%MOD;
		if(ret1<0)
			ret1+=MOD;

		ll ret2=((1+f)*(s))%MOD;
		if(ret2<0)
			ret2+=MOD;

		return mp(ret1,ret2);
	}

	else
	{
		ii val=fast_exp(base,exp-1,MOD);
		ll f=val.F;
		ll s=val.S;
		
		ll ret1=(base*f)%MOD;
		if(ret1<0)
		ret1+=MOD;

		ll ret2=(1+((base*s)%MOD))%MOD;
		if(ret2<0)
			ret2+=MOD;

		return mp(ret1,ret2);
	}
}
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	ll a,n,m;
  	cin>>a>>n>>m;
    
  	if(a==0)
  	{
  		cout<<0<<endl;
  		continue;
  	}

    if(n==1)
    {
    	ll rem=a%m;
    	if(rem<0)
    		rem+=m;
    	cout<<rem<<endl;
    	continue;
    }
  	
  	int dig=0;
  	ll temp=a;
  	while(temp>0)
  	{
  		dig++;
  		temp/=10;
  	}

  	ll val=1;
  	
  	FOR(i,1,dig)
  	val*=10;
  	
  	ii ans=fast_exp(val,n-1,m);

  	ll rem=a%m;
  	if(rem<0)
  		rem+=m;

  	ll final=(rem*ans.S)%m;
  	if(final<0)
  		final+=m;

  	cout<<final<<endl;
  }
  return 0;
}