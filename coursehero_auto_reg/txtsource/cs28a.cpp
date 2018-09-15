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
int n;
ll L;
ll mini[N],maxi[N];
bool check(ll val)
{
	ll total=0;
	FOR(i,1,n)
	{
		total+=min(maxi[i],val);
	}

	return (total>=L);
}

bool check2(ll val)
{
	ll total=0;
	FOR(i,1,n)
	{
		total+=max(val,mini[i]);
	}

	return (total<=L);
}

int main(){
  fast;
  cin>>n>>L;
  ll l=-1;
  ll r=-1;
  FOR(i,1,n)
  {
  	cin>>mini[i]>>maxi[i];
  	l=max(mini[i],l);
  	r=max(maxi[i],r);
  }

  ll ans;
  while(r-l>1)
  {
  	ll mid=(l+r)/2;
  	if(check(mid))
  	r=mid;
  	else
  	l=mid;
  }

  if(check(l))
  ans=l;
  else
  ans=r;

  //cout<<ans<<endl;	
	
  l=INF;
  r=INF;

  FOR(i,1,n)
  {
  	l=min(l,mini[i]);
  	r=min(r,maxi[i]);
  }
  	
  while(r-l>1)
  {
  	ll mid=(l+r)/2;
  	if(check2(mid))
  		l=mid;
  	else
  		r=mid;
  }

  if(check2(r))
  	ans=ans-r;
  else
  	ans=ans-l;

  cout<<ans;
  return 0;
}