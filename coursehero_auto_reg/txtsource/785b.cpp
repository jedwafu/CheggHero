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
  int n,m;
  cin>>n;
  int l1,r1,l2,r2;
  l1=l2=0;
  r1=r2=mod;
  FOR(i,1,n)
  {
  	int l,r;
  	cin>>l>>r;
  	l1=max(l1,l);
  	r1=min(r1,r);	
  }
  cin>>m;
  FOR(i,1,m)
  {
	int l,r;
	cin>>l>>r;
	l2=max(l2,l);
	r2=min(r2,r);  	
  }

  int ans=max(l2-r1,l1-r2);
  cout<<max(ans,0);
  return 0;
}