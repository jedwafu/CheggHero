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
int c[N];
vi tree[N];
int dis[N];
int aux[N];
int mismtch[N];
int par[N];

void maketree(int source,int parent)
{
	par[source]=parent;
	FOR(i,0,sz(edges[source])-1)
	{
		if(edges[source][i]!=parent)
		{
			tree[source].pb(edges[source][i]);
			maketree(edges[source][i],source);
		}
	}
}

void dfs(int source)
{
	dis[source]=1;
	mismtch[source]=0;
	FOR(i,0,sz(tree[source])-1)
	{
		dfs(tree[source][i]);
		if(dis[tree[source][i]]>1 or c[tree[source][i]]!=c[source])
		{
			dis[source]=2;
			mismtch[source]++;
		}
	}
}

void dfs2(int source)
{
	aux[source]=1;
	if(source!=1)
	{
		if(mismtch[par[source]]==0 and aux[par[source]]==1 and c[par[par[source]]]==c[par[source]])
		{
			aux[source]=1;
		}


		else if(mismtch[par[source]]==1 and (c[par[source]]!=c[source] or dis[source]>1) and aux[par[source]]==1 and c[par[par[source]]]==c[par[source]])
			aux[source]=1;
		else
			aux[source]=2;
	}	

	FOR(i,0,sz(tree[source])-1)
	dfs2(tree[source][i]);
}

int main(){
  fast;
  int n;
  cin>>n;
  fill(dis,0);
  fill(mismtch,0);
  fill(aux,0);
  FOR(i,1,n-1)
  {
  	int u,v;
  	cin>>u>>v;
  	edges[u].pb(v);
  	edges[v].pb(u);
  }
  FOR(i,1,n)
  cin>>c[i];

  aux[0]=1;
  c[0]=c[1];
  maketree(1,0);
  dfs(1);
  dfs2(1);
  FOR(i,1,n)
  {
  	bool ans=true;
  	FOR(j,0,sz(tree[i])-1)
  	{
  		if(dis[tree[i][j]]>1)
  			ans=false;
  	}	
  	if(aux[i]>1)
  		ans=false;

  	if(ans)
  	{
  		cout<<"YES"<<endl;
  		cout<<i;
  		return 0;
  	}
  }
  cout<<"NO";
  return 0;
}