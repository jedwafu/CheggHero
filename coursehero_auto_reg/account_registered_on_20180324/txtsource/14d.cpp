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
const int N = 210; 

vi edges[N];
vector<ii> edge;
int ans[2];
int dfs(int root,int parent,int index)
{
	int maxi=0;
   FOR(i,0,sz(edges[root])-1)
   {
   	
   	if(edges[root][i]!=parent)
   	{
   		int temp=1+dfs(edges[root][i],root,index);
   		maxi=max(maxi,temp);
   		ans[index]=max(ans[index],temp);
        FOR(j,i+1,sz(edges[root])-1)
        {
    	    if(edges[root][j]!=parent)
    	    ans[index]=max(ans[index],1+dfs(edges[root][j],root,index)+temp);
        }
    }

   }
   
   return maxi;
}



int main(){
  fast;
  int n;
  cin>>n;
  FOR(i,1,n-1)
  {
  	int u,v;
  	cin>>u>>v;
  	edge.pb(mp(u,v));
  	edges[u].pb(v);
  	edges[v].pb(u);
  }
  int final=0;
  FOR(i,0,sz(edge)-1)
  {
  	ans[0]=ans[1]=0;
  	int temp=dfs(edge[i].F,edge[i].S,0);
  	temp=dfs(edge[i].S,edge[i].F,1);	
  	final=max(final,ans[0]*ans[1]);
  }
  cout<<final<<endl;

  return 0;
}