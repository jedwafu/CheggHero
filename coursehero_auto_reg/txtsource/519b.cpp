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
  int n;
  cin>>n;

  ll sums=0,tsums=0;
  FOR(i,1,n)
  {
  	ll a;
  	cin>>a;
  	sums+=a;
  }

  FOR(i,1,n-1)
  {
  	ll a;
  	cin>>a;
  	tsums+=a;
  }
  cout<<sums-tsums<<endl;
  sums=tsums;
  tsums=0;
  FOR(i,1,n-2)
  {
  	ll a;
  	cin>>a;
  	tsums+=a;
  }
  cout<<sums-tsums;
  return 0;
}
