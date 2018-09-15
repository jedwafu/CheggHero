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
const int N = 4e5+5; 

ll fac[N];
ll invfac[N];

// Thank you to rajat1603 for this method of calculating inverse factorials.
void FAC()
{
	fac[0]=1;
	FOR(i,1,N)
	fac[i]=(fac[i-1]*i)%mod;

	invfac[N-1]=977041169;
	NFOR(i,N-2,0)
	invfac[i]=(invfac[i+1]*(i+1))%mod;
}

ll ncr(ll n,ll r)
{
	if(r>=0 and r<=n)
	{
		ll res=fac[n];
		res=(res*invfac[r])%mod;
		res=(res*invfac[n-r])%mod;
		return res;
	}
	return 0;
}

string s;
int main()
{
  fast;
  cin>>s;
  ll x=0,y=0,yt=0;
  
  FAC();

  FOR(i,0,sz(s)-1)
  if(s[i]==')')
  	yt++;

  ll ans=0;
  FOR(i,0,sz(s)-1)
  {
  	if(s[i]=='(')
  	{
  		ans=(ans+ncr(x+yt-y,yt-y-1))%mod;
  		x++;
  	}
  	else
  		y++;
  }
  cout<<ans;
   return 0;
}