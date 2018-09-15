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
const int N = 1e6+10; 

ll arr[N];
vector<ii> seg;

int main()
{
  fast;
  int n;
  ll l,r;
  cin>>n>>l>>r;
  
  seg.clear();

  FOR(i,0,n-1)
  cin>>arr[i];

  sort(arr,arr+n);
  
  ll lower,upper;
  ll ans=0;

  FOR(i,1,n-1)
  {
  	lower=max(l,arr[i]-arr[i-1]+1);
  	upper=min(r,arr[i]+arr[i-1]-1);
  	seg.pb(mp(lower,upper));
  }

  sort(seg.begin(),seg.end());
  upper=l-1;
  FOR(i,0,n-2)
  {
  	if(seg[i].F<=upper)
  	{
  		seg[i].F=upper+1;
  	}
  	
  	if(seg[i].S>=seg[i].F)
  	{
  		ans+=seg[i].S-seg[i].F+1;
  		upper=seg[i].S;
  	}
  }

  cout<<ans;
  return 0;
}