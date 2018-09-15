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
const ll INF = 1e9+10;
const ll mod = 1e9+7;
const int N = 1e5+10; 

bool check(ll a,ll b,ll c)
{
	return (a*b >= c);
}

int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	ll x,y,p,q;
  	cin>>x>>y>>p>>q;
  	if((p==0 and x==0) or(p==q and x==y))
  	{
  		cout<<0<<endl;
  		continue;
  	}
  	if(p==0 and x!=0)
  	{
  		cout<<-1<<endl;
  		continue;
  	}
  	if(p==q and x<y)
  	{
  		cout<<-1<<endl;
  		continue;
  	}

  	if((x/__gcd(x,y))==p and (y/__gcd(x,y))==q)
  	{
  		cout<<0<<endl;
  		continue;
  	}

  	ll ans=0;

  	ll l=1;
  	ll r=INF;
 	while(r-l>1)
 	{
 		ll mid=(l+r)/2;
 		if(check(mid,p,x))
 		r=mid;
 		else
 		l=mid;
 	}
 	if(check(l,p,x))
 	ans=max(ans,l);
 	else if(check(r,p,x))
 	ans=max(ans,r);
 	else
 	{
 		cout<<-1<<endl;
 		continue;
 	}

 	 l=1;
  	 r=INF;
 	while(r-l>1)
 	{
 		ll mid=(l+r)/2;
 		if(check(mid,q,y))
 		r=mid;
 		else
 		l=mid;
 	}
 	if(check(l,q,y))
 	ans=max(ans,l);
 	else if(check(r,q,y))
 	ans=max(ans,r);
 	else
 	{
 		cout<<-1<<endl;
 		continue;
 	}

 	 l=1;
  	 r=INF;
 	while(r-l>1)
 	{
 		ll mid=(l+r)/2;
 		if(check(mid,q-p,y-x))
 		r=mid;
 		else
 		l=mid;
 	}
 	if(check(l,q-p,y-x))
 	ans=max(ans,l);
 	else if(check(r,q-p,y-x))
 	ans=max(ans,r);
 	else
 	{
 		cout<<-1<<endl;
 		continue;
 	}

 	//cout<<ans<<endl;
 	if(ans)
 	cout<<ans*q-y<<endl;
 	else
 	cout<<0<<endl;
 	continue;
  }

  return 0;
}