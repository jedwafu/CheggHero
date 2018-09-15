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
vi tree[N];
int col[N];
void maketree(int source,int par)
{
	FOR(i,0,sz(edges[source])-1)
	{
		if(edges[source][i]!=par)
		{
			tree[source].pb(edges[source][i]);
			maketree(edges[source][i],source);
		}
	}

}
void dfs(int source,int par)
{
	int clr=1;
	FOR(i,0,sz(tree[source])-1)
	{
		while(col[source]==clr or col[par]==clr)
			clr++;

		col[tree[source][i]]=clr;
		clr++;
	}

	FOR(i,0,sz(tree[source])-1)
	dfs(tree[source][i],source);
}

int main(){
  fast;
  int n;
  cin>>n;
  FOR(i,1,n-1)
  {
  	int x,y;
  	cin>>x>>y;
  	edges[x].pb(y);
  	edges[y].pb(x);
  }
  maketree(1,0);
  int ans=1+sz(tree[1]);
  FOR(i,2,n)
  ans=max(ans,2+sz(tree[i]));

  cout<<ans<<endl;
  col[0]=0;
  col[1]=1;

  dfs(1,0);
  FOR(i,1,n)
  cout<<col[i]<<" ";
  return 0;
}