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
const int N = 2e3+10; 
int d,n;
int arr[N];
vi edges[N];
vi tree[N];
int par[N];
ll ans[N];
bool done[N][N];
void maketree(int root)
{
	FOR(i,0,sz(edges[root])-1)
	{
        if(edges[root][i]!=par[root])
        {
        	par[edges[root][i]]=root;
        	tree[root].pb(edges[root][i]);
        	maketree(edges[root][i]);
        }
	}
}

ll dfs2(int root,int val,int parent,int original)
{
      if(arr[root]<val or arr[root]>val+d or done[original][root] or done[root][original])
      	return 0;
      
      done[original][root]=true;
     // cout<<"going from "<<parent<<" to "<<root<<endl;

      ll temp=1;
      FOR(i,0,sz(tree[root])-1)
      {
      	if(tree[root][i]!=parent)
      	{
      		//cout<<"going from "<<root<<" to "<<tree[root][i]<<endl;
      		temp=(temp*((1+dfs2(tree[root][i],val,root,original))%mod))%mod;
      	}
      }
      

     if(par[root]!=parent)
   	 {
   	 	//cout<<"going from "<<root<<" to "<<par[root]<<endl;
   	 	temp=(temp*(1+dfs2(par[root],val,root,original))%mod)%mod;
   	 }

      return temp;
}

void dfs(int root)
{
   
   FOR(i,0,sz(tree[root])-1)
   dfs(tree[root][i]);
   
   ans[root]=dfs2(root,arr[root],0,root); 
   //cout<<root<<" "<<ans[root]<<endl;
}

int main(){
  fast;
  
  cin>>d>>n;
  fill(done,0);
  arr[0]=-1;
  FOR(i,1,n)
  cin>>arr[i];
  
  FOR(i,1,n-1)
  {
  	int u,v;
  	cin>>u>>v;
  	edges[u].pb(v);
  	edges[v].pb(u);
  }
  par[1]=0;
  maketree(1);
  dfs(1);
  
  ll final=0;
  FOR(i,1,n)
  final=(final+ans[i])%mod;
  cout<<final;
  return 0;
}