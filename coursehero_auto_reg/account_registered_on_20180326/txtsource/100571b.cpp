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

ll func[N];
ll x[N];

void calc()
{
	FOR(i,3,N-1)
	func[i]=(a*func[i-2]+b*func[i-1])%mod;
}

int main(){
  fast;
  int n,q,a,b;
  cin>>n>>q;
  cin>>func[1]>>func[2];
  cin>>a>>b;

  calc();

  FOR(i,1,n)
  cin>>x[i];

  FOR(i,1,q)
  {
  	int l,r;
  	
  }
  return 0;
}