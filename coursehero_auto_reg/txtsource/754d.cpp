#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

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
const int N = 3e5+10; 

int lt[N],rt[N];
vector<ii> seg;
priority_queue<int> q;
vi final;
int main(){
  fast;
  int n,k;
  cin>>n>>k;
  FOR(i,1,n)
  {
  	int l,r;
  	cin>>l>>r;
  	seg.pb(mp(l,-i));
  	seg.pb(mp(r,i));
  	rt[i]=r;
  	lt[i]=l;
  }
  
  sort(seg.begin(),seg.end());
  int ans=0;
  int start=0;
  
  FOR(i,0,2*n-1)
  {
  	if(seg[i].S<0)
  	{
  		q.push(-rt[-seg[i].S]);
  		while(sz(q)>k)
  			q.pop();

  		if(q.size()==k)
  		{
  			ans=max(ans,-q.top()-seg[i].F+1);
  			if(ans==-q.top()-seg[i].F+1)
  				start=seg[i].F;
  		}
  	}
  }

  if(ans==0)
  {
  	cout<<0<<endl;
  	FOR(i,1,k)
  	cout<<i<<" ";
  	return 0;
  }

  cout<<ans<<endl;
  FOR(i,1,n)
  {
  	if(k>0 and lt[i]<=start and rt[i]>=start+ans-1)
  	{
  		final.pb(i);
  		k--;
  	}
  }

  FOR(i,0,sz(final)-1)
  cout<<final[i]<<" ";
  return 0;
}