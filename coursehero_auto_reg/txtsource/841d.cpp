#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 3e5+10; 

int d[N];
int deg[N];
vector< pair<int,int> > edges[N];
bool taken[N];
bool vis[N];
int par[N];

void dfs(int s,int p,int e)
{
	par[s]=p;
	if(p)
	deg[s]++;
	for(int i=0;i<sz(edges[s]);i++)
	{
		if(edges[s][i].F==p or vis[edges[s][i].F])
			continue;

		vis[edges[s][i].F]=true;
		deg[s]++;
		dfs(edges[s][i].F,s,edges[s][i].S);
	}

	//cout<<s<<" "<<deg[s]<<endl;
	if(p and d[s]!=-1 and (deg[s]%2) != d[s])
	{
		//cout<<"not taking "<<e<<endl;
		taken[e]=false;
		deg[p]--;
	}
	else
	{
		taken[e]=true;
	}
}

int main(){
  fast;
  int n,m;
  cin>>n>>m;
  int flag=0;

  fill(deg,0);
  fill(taken,0);
  fill(vis,0);

  bool already=true;
  FOR(i,1,n)
  {
  	edges[i].clear();
  	cin>>d[i];
  	if(d[i]==-1)
  		flag=i;
  	if(m==0 and d[i]==1)
  		already=false;
  }

  if(already==false)
  {
  	cout<<"-1"<<endl;
  	return 0;
  }
  
  FOR(i,1,m)
  {
  	int u,v;
  	cin>>u>>v;
  	edges[u].pb(mp(v,i));
  	edges[v].pb(mp(u,i));
  }

  int root;
  if(flag)
  	root=flag;
  else root=1;

  vis[root]=true;
  dfs(root,0,0);

  
  if(d[root]==-1 or (deg[root]%2)==d[root])
  {
  	int cnt=0;
  	FOR(i,1,m)
  	if(taken[i])
  		cnt++;
  	cout<<cnt<<endl;
  	FOR(i,1,m)
  	if(taken[i])
  		printf("%d\n",i);
  }
  else
  	cout<<"-1"<<endl;
  return 0;
}