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
const int N = 1e3+10; 

bool rows[N];
bool cols[N];
int main(){
  fast;
  fill(rows,0);
  fill(cols,0);
  int n,m;
  cin>>n>>m;
  int ans=0;
  FOR(i,1,m)
  {
  	int a,b;
  	cin>>a>>b;
  	rows[a]=true;
  	cols[b]=true;
  }
  
  FOR(i,2,n-1)
  {
      if(!rows[i])
      	ans++;
      if(!cols[i])
      	ans++;
  }

  if(n%2)
  if(!rows[(n+1)/2] and !cols[(n+1)/2])
     ans--;
  
  cout<<ans;
    return 0;
}