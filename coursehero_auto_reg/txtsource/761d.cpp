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

ll a[N];
ll p[N];
ll b[N];
int main()
{
  fast;
  int n,l,r;
  cin>>n>>l>>r;
  
  FOR(i,1,n)
  cin>>a[i];
  
  FOR(i,1,n)
  cin>>p[i];
  
  ll mini=mod;
  ll maxi=0;
  FOR(i,1,n)
  {
  	b[i]=p[i]+a[i];
  	mini=min(mini,b[i]);
  	maxi=max(maxi,b[i]);
  }

  if(mini<l)
  {
  	if(maxi+(l-mini)>r)
  	  {
  	  	cout<<-1;
  	  	return 0;
  	  }

  	  FOR(i,1,n)
  	  b[i]+=l-mini;
  }

  else if(maxi>r)
  {
  	if(mini-(maxi-r)<l)
  	{
  		cout<<-1;
  		return 0;
  	}
  	FOR(i,1,n)
  	b[i]-=maxi-r;
  } 

   FOR(i,1,n)
   cout<<b[i]<<" ";
  

  return 0;
}