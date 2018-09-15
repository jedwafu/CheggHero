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
const int N = 2e5+10; 

vi edges[N];
bool done[N];
ll ver,edg;
bool dfs(int source,int par)
{
	done[source]=true;
	ver++;

	edg+=sz(edges[source]);

	FOR(i,0,sz(edges[source])-1)
	{
		if(edges[source][i]==par or done[edges[source][i]])
			continue;
		bool dummy=dfs(edges[source][i],source);
	}
	
	if(ver*(ver-1)==edg)
		return true;

	return false;
}

int main(){
  fast;
  int n,m;
  cin>>n>>m;
  
  fill(done,0);
  
  FOR(i,1,m)
  {
  	int a,b;
  	cin>>a>>b;
  	edges[a].pb(b);
  	edges[b].pb(a);
  }

  

  FOR(i,1,n)
  {
  	if(!done[i])
  	{
  		ver=edg=0;
  		if(!dfs(i,0))
  		{
  			cout<<"NO";
  			return 0;
  		}
  	}
  }
  //cout<<ver<<" "<<edg<<endl;
  cout<<"YES";
  return 0;
}