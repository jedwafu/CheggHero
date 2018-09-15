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
const int N = 1e5+10; 
const int LN = 17;

vector<ii> edges[N];
int path[N];
int dp[LN][N];
int LCA[N];
int ansfor[N];
int depth[N];

void dfs(int node , int parent){
    depth[node] = depth[parent] + 1;
    dp[0][node] = parent;
    FOR(i,0,sz(edges[node])-1){
        if(edges[node][i].F!= parent){
            dfs(edges[node][i].F , node);
            //sum[node] += sum[next];
        }
    }
}

int lca(int a , int b){
    if(depth[a] < depth[b]){
        swap(a , b);
    }
    int dif = depth[a] - depth[b];
    for(int i = 0 ; i < LN ; ++i){
        if(dif & (1 << i)){
            a = dp[i][a];
        }
    }
    if(a != b){
        for(int i = LN - 1 ; i >= 0 ; --i){
            if(dp[i][a] != dp[i][b]){
                a = dp[i][a];
                b = dp[i][b];
            }
        }
        a = dp[0][a];
    }
    return a;
}

void dfs2(int s,int p)
{
	int road=0;
	FOR(i,0,sz(edges[s])-1)
	{
		if(edges[s][i].F==p)
		{
			road=edges[s][i].S;
			continue;
		}
 
		dfs2(edges[s][i].F,s);
	}
	
	if(sz(edges[s])==1 and edges[s][0].F==p)
	{
		ansfor[road]=path[s];
		return;
	}	

	ansfor[road]=path[s];
	FOR(i,0,sz(edges[s])-1)
	{
		if(edges[s][i].F==p)
			continue;
		ansfor[road]+=ansfor[edges[s][i].S];
	}

	ansfor[road]-=2*LCA[s];

	//cout<<"At "<<s<<" and ansfor "<<road<<" is "<<sz(openroads)<<endl;
	return;
}

int main(){
  fast;
  int n,k;
  cin>>n;
  fill(ansfor,0);
  fill(LCA,0);
  fill(dp,0);
  fill(path,0);
  fill(depth,0);

  FOR(i,1,n-1)
  {
  	int u,v;
  	cin>>u>>v;
  	edges[u].pb(mp(v,i));
  	edges[v].pb(mp(u,i));
  }

  dfs(1 , 0);
  for(int i = 1 ; i < LN ; ++i)
  {
      for(int j = 1 ; j <= n ; ++j)
      dp[i][j] = dp[i - 1][dp[i - 1][j]]; 
  }

  cin>>k;
  FOR(i,1,k)
  {
  	int u,v;
  	cin>>u>>v;
  	path[u]++;
  	path[v]++;
  	LCA[lca(u,v)]++;
  }

  dfs2(1,0);
  FOR(i,1,n-1)
  cout<<ansfor[i]<<" ";

  return 0;
}