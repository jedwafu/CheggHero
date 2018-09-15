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
int a[N];
bool vis[N];
vi arr;
int parent[N];

bool flag=true;
void dfs(int source,int par)
{
	vis[source]=true;
	FOR(i,0,sz(edges[source])-1)
	{
		if(edges[source][i]==par or vis[edges[source][i]])
			continue;
		dfs(edges[source][i],source);
	}

	if(a[source]==source)
		arr.pb(source);

	else if(par)
	{
		if(a[source]!=a[par])
		{
			flag=false;
			return ;
		}
	}
}

int main(){
  fast;
  int n,m;
  cin>>n>>m;

  fill(vis,0);
  fill(parent,0);
  arr.clear();
  FOR(i,1,m)
  {
  	int p,q;
  	cin>>p>>q;
  	edges[p].pb(q);
  	parent[q]=p;
  }

  FOR(i,1,n)
  cin>>a[i];

  FOR(i,1,n)
  {
  	if(!vis[i])
  	{
  		dfs(i,parent[i]);
  		if(!flag)
  		{
  			cout<<-1;
  			return 0;
  		}
  	}
  }

  cout<<sz(arr)<<endl;
  FOR(i,0,sz(arr)-1)
  cout<<arr[i]<<endl;
  return 0;
}