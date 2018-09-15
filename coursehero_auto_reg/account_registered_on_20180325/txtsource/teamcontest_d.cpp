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

ll degree[10010];

int main(){
  
  FILE *fin = freopen("matrix.in","r",stdin);

  FILE *fout = freopen("matrix.out","w",stdout);


  fast;
  ll n,m;
  cin>>n>>m;
  FOR(i,0,10009)
  degree[i]=0;

  FOR(i,1,m)
  {
  	ll a,b;
  	cin>>a>>b;
  	degree[a]++;
  	degree[b]++;
  } 
  ll sums=0;
  FOR(i,1,n)
  {
  	degree[i]*=degree[i];
    sums+=degree[i];
  }
  cout<<sums<<endl;
  return 0;
}