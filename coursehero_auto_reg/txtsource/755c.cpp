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
const int N = 1e4+10; 

int arr[N];
bool done[N];
vector<int> G[N];

void dfs(int source)
{
	done[source]=true;

	FOR(i,0,sz(G[source])-1)
	{
		if(!done[G[source][i]])
			dfs(G[source][i]);
	}
}

int main(){
  fast;
  int n;
  cin>>n;
  fill(done,0);
  FOR(i,1,n)
  {
  	int temp;
  	cin>>temp;
  	G[i].pb(temp);
  	G[temp].pb(i);
  }

  int ans=0;
  for(int i=1;i<=n;i++)
  {
  	if(!done[i])
  	{
  		ans++;
  		dfs(i);
  	}
  }
  cout<<ans;
  return 0;
}