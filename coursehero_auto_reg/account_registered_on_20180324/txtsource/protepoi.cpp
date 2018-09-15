#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
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

ll n,k,m;
vector<ii> rows;
vector<ii> cols;

ll calcrows(ll stx)
{
	if(rows.empty() or  rows[0].F != stx)
		return 0;

	int idx=0;
	ll cnt=0;
	ll ends=stx-1;
	ll newends=stx-1;
	ll cur=stx;

	while(cur < stx+k)
	{
		
		newends=ends;
		while(idx < sz(rows) and rows[idx].F == cur)
		{
			newends=max(newends,rows[idx].S);
			idx++;
		}
		
		

		if(newends < cur)
			return 0;

		cnt++;
		cur=newends+1;
		

		ends=newends;
		while(idx < sz(rows) and rows[idx].F <= newends)
		{
			ends=max(ends,rows[idx].S);
			idx++;
		}
		
	}	

	if(cur >= stx+k-1)
		return cnt;
	else
		return 0;
}

ll calccols(ll stx)
{
	if(cols.empty() or  cols[0].F != stx)
		return 0;

	int idx=0;
	ll cnt=0;
	ll ends=stx-1;
	ll newends=stx-1;
	ll cur=stx;

	while(cur < stx+k)
	{
		
		newends=ends;
		while(idx < sz(cols) and cols[idx].F == cur)
		{
			newends=max(newends,cols[idx].S);
			idx++;
		}
		
		if(newends < cur)
			return 0;

		cnt++;
		cur=newends+1;
		

		ends=newends;
		while(idx < sz(cols) and cols[idx].F <= newends)
		{
			ends=max(ends,cols[idx].S);
			idx++;
		}
		
	}	

	if(cur >= stx+k-1)
		return cnt;
	else
		return 0;
}

int main()
{
	
  //freopen("in.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);	
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	rows.clear();
  	cols.clear();
  	
  	cin>>n>>k>>m;
  	
  	ll stx,sty;
  	stx=sty=(n-k)/2+1;
  	
  	FOR(i,1,m)
  	{
  		ll x1,y1,x2,y2;
  		cin>>x1>>y1>>x2>>y2;
  		if(x1==x2)
  		{
  			if(x1 >= stx and x1 < stx+k)
  			rows.pb(mp(x1,x1));
  			else
  			{
  				if(y1>y2)
  					swap(y1,y2);	
  				
  				y1=max(sty,y1);
  				y2=min(sty+k-1,y2);
  				if(y2>=y1)
  				cols.pb(mp(y1,y2));	
  			}		
  		}
  		else if(y1 == y2)
  		{
  			if(y1 >= sty and y1 < sty+k)
  			cols.pb(mp(y1,y1));
  			else
  			{
  				if(x1>x2)
  					swap(x1,x2);

  				x1=max(stx,x1);
  				x2=min(stx+k-1,x2);
  				if(x2>=x1)
  					rows.pb(mp(x1,x2));
  					
  			}
  		}
  	}

  	sort(rows.begin(),rows.end());
  	sort(cols.begin(),cols.end());

  	ll ans1=calcrows(stx);
  	ll ans2=calccols(sty);
  	
  	if(!ans1 or !ans2)
  	cout<<-1<<endl;
  	else
  	cout<<ans1+ans2<<endl;
  }
  return 0;
}