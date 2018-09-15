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

vi edges[N];
int deg[N];
bool yes[N];

int main(){
  fast;
  int n;
  cin>>n;
  fill(deg,0);
  fill(yes,0);

  FOR(i,1,n-1)
  {
  	int u,v;
  	cin>>u>>v;
  	edges[u].pb(v);
  	edges[v].pb(u);
  	deg[u]++;
  	deg[v]++;
  }

  FOR(i,1,n)
  {
  	int cnt=0;
  	FOR(j,0,sz(edges[i])-1)
  	{
  		if(deg[edges[i][j]]==1)
  			{
  				cnt++;
  				yes[i]=true;
  			}
  	}

  	if(cnt>1)
  	{
  		cout<<"First";
  		return 0;
  	}
  }

  FOR(i,1,n)
  {
  	int cnt=0;
  	FOR(j,0,sz(edges[i])-1)
  	{
  		if(yes[edges[i][j]])
  			cnt++;
  	}
  	if(cnt>1 and cnt==sz(edges[i]))
  	{
  		cout<<"First";
  		return 0;
  	}
  }

  cout<<"Second";
  return 0;
}