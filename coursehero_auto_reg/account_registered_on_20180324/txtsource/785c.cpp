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

int main(){
  fast;
  ll n,m;
  cin>>n>>m;
  if(m>=n)
  {
  	cout<<n;
  	return 0;
  }
  
  ll l=1,r=2e9;
  while(r-l>1)
  {
  	ll mid=(l+r)/2;
  	if(n-((mid*(mid+1))/2)<=m)
  		r=mid;
  	else
  		l=mid;
  }
  if(n-((l*(l+1))/2)<=m)
  	cout<<l+m;
  else
  	cout<<r+m;
  return 0;
}