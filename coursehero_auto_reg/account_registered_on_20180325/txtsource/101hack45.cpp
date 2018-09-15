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


ll s[5*N];
ll pows[N];
ll c[N];

void EE(ll a, ll b, ll& x, ll& y)
{
    if(a%b == 0)
    {
        x=0;
        y=1;
        return;
    }
    EE(b,a%b,x,y);
    ll temp = x;
    x = y;
    y = temp - y*(a/b);
}

ll inverse(ll a, ll m)
{
    ll x,y;
    EE(a,m,x,y);
    if(x<0) x += m;
    return x;
}

void calc(ll val)
{
	pows[0]=1;
	pows[1]=val;

	FOR(i,2,N-1)
	{
		pows[i]=(val*pows[i-1])%mod;
		if(pows[i]<0)
			pows[i]+=mod;
	}
}

void build(int curr,int l,int r){
  if(l == r){
    s[curr] = c[l]%mod;
    if(s[curr]<0)
    	s[curr]+=mod;

    return;
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  build(c1,l,mid);
  build(c2,mid+1,r);
  s[curr] = (s[c1] + (pows[mid-l+1]*(s[c2]))%mod)%mod;
  
  if(s[curr]<0)
  	s[curr]+=mod;
}

void update(int curr,int l,int r,int index,ll upd){
  if(l==r){
      s[curr]=upd%mod;
      if(s[curr]<0)
      	s[curr]+=mod;
      return ;
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  if(index<=mid)
  update(c1,l,mid,index,upd);
  else
  update(c2,mid+1,r,index,upd);
  s[curr] = (s[c1] + (pows[mid-l+1]*(s[c2]))%mod)%mod;
  if(s[curr]<0)
  	s[curr]+=mod;
}

ll query(int curr,int l,int r,int x,int y){
  if(l > y || r < x)return 0;
  if(x <= l && r <= y){
    return s[curr];
  }
  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  ll q = (query(c1,l,mid,x,y) + (pows[mid-l+1]*query(c2,mid+1,r,x,y))%mod)%mod;
  if(q >= mod)q-=mod;
  if(q<0)
  	q+=mod;
  return q;
}


int main(){
  fast;
  ll n,a,b,q;
  cin>>n>>a>>b>>q;

  a=inverse(a,mod);
  b=(a*(b))%mod;
  if(b<0)
  	b+=mod;

  if(b)
  b=mod-b;

  calc(b);
  
  FOR(i,0,n-1)
  cin>>c[i];

 build(1,0,n-1);
 FOR(i,1,q)
 {
 	ll t,a,b;
 	cin>>t>>a>>b;
 	if(t==1)
 	update(1,0,n-1,a,b);
 	if(t==2)
 	{
 		if(query(1,0,n-1,a,b))
 			cout<<"No"<<endl;
 		else
 			cout<<"Yes"<<endl;
 	}
 }	

  return 0;
}