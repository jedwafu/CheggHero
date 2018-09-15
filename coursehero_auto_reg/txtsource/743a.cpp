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

ll arr[200010];
vector<int> edges[200010];
vector<int> tree[200010];
vector<ll> calc[200010];
ll value[200010];
ll maxval[200010];
void maketree(int par,int root)
{
	//cout<<"here";
   for(int i=0;i<edges[root].size();i++)
   {
   	
   	 if(edges[root][i]!=par)
    {	
    	tree[root].push_back(edges[root][i]);
   	    maketree(root,edges[root][i]);
    }

    //cout<<i;  
   }
}

ll inf=(ll)1e10;

ll dfs(int root)
{
    //cout<<"here";
	if(tree[root].empty())
	{
		value[root]=arr[root];
		maxval[root]=arr[root];
		return value[root];
	}

	
	value[root]=arr[root];
	
	for(int i=0;i<tree[root].size();i++)
	{
      value[root]+=dfs(tree[root][i]); 
	}
	maxval[root]=value[root];
	for(int i=0;i<tree[root].size();i++)
	{
		maxval[root]=max(maxval[root],maxval[tree[root][i]]);
    } 		
	//cout<<root<<" "<<maxval[root]<<endl;
	return value[root];
}

ll ans=(-1)*inf;

void func(int root)
{
  if(tree[root].empty())
    return;

  ll temp=(-1)*inf;
  if(tree[root].size()>1)
	{
    for(int i=0;i<tree[root].size();i++)
    {
        calc[root].pb(maxval[tree[root][i]]);
    }
    sort(calc[root].begin(),calc[root].end());
    reverse(calc[root].begin(),calc[root].end());
    ans=max(ans,calc[root][0]+calc[root][1]);
  }
   
   for(int i=0;i<tree[root].size();i++)
    {
        func(tree[root][i]);
    }
    
}

int main(){
  fast;
  int n;
  cin>>n;
  FOR(i,1,n)
  cin>>arr[i];
  if(n==1)
  {
  	cout<<"Impossible";
  	return 0;
  }

  FOR(i,1,n-1)
  {
  	int u,v;
  	cin>>u>>v;
  	edges[u].pb(v);
  	edges[v].pb(u);
  }
  maketree(0,1);
  ll a=dfs(1);
  
  func(1);
  
  if(ans==(-1)*inf)
    cout<<"Impossible";
  else
    cout<<ans;
  return 0;
}