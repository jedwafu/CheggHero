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
vi tree[N];
int par[N];
ll arr[N];

void maketree(int root)
{
	if(edges[root].empty())
		return;

     FOR(i,0,sz(edges[root])-1)
     {
     	//cout<<root<<" "<<edges[root][i]<<endl;
     	if(edges[root][i]!=par[root])
     	{   
     		par[edges[root][i]]=root;
     		tree[root].pb(edges[root][i]);
     		maketree(edges[root][i]);
     	}
     }
}

ll decr[N];
ll incr[N];
void dfs(int root)
{
	if(tree[root].empty())
	{
		if(arr[root]<0)
		incr[root]=-arr[root];
	    else
	    decr[root]=arr[root];
		return;
	}
	
    ll minneg=0;
    ll maxpos=0;
	FOR(i,0,sz(tree[root])-1)
	dfs(tree[root][i]);
	
	
	FOR(i,0,sz(tree[root])-1)
	{
	    incr[root]=max(incr[root],incr[tree[root][i]]);
	    decr[root]=max(decr[root],decr[tree[root][i]]);
	}
	//cout<<root<<" incr "<<incr[root]<<endl;
	//cout<<root<<" decr"<<decr[root]<<endl;

	    arr[root]+=incr[root]-decr[root];
    if(arr[root]<0)
		incr[root]-=arr[root];
	else
	    decr[root]+=arr[root];
}


int main(){
  fast;
  int n;
  cin>>n;
  fill(incr,0);
  fill(decr,0);
  FOR(i,1,n-1)
  {
  	int u,v;
  	cin>>u>>v;
  	edges[u].pb(v);
  	edges[v].pb(u);
  }
  FOR(i,1,n)
  cin>>arr[i];
 
  par[1]=0;
  maketree(1);
  dfs(1);
  cout<<incr[1]+decr[1];
  
  return 0;
}