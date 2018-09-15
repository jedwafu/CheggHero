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
const int N = 3e5+10; 

int tot[N];
int color[N];
int used[N];
vi tp[N];
vi edges[N];

void dfs(int s,int par)
{
	
		int clr=1;
		FOR(i,0,sz(tp[s])-1)
		{
			if(color[tp[s][i]])
			{
				used[color[tp[s][i]]]=s;
			}
		}

		FOR(i,0,sz(tp[s])-1)
		{
			if(color[tp[s][i]])
				continue;
			while(used[clr]==s)
				clr++;
			color[tp[s][i]]=clr;
			used[clr]=s;
		}

		FOR(i,0,sz(edges[s])-1)
		{
			if(edges[s][i]==par)
				continue;
			dfs(edges[s][i],s);
		}
}

int main(){
  fast;
  int n,m;
  cin>>n>>m;
  fill(used,0);
  fill(color,0);
  FOR(i,1,n)
  {
  	cin>>tot[i];
  	FOR(j,1,tot[i])
  	{	
  		int temp;
  		cin>>temp;
  		tp[i].pb(temp);
  	}
  }

  FOR(i,1,n-1)
  {
  	int u,v;
  	cin>>u>>v;
  	edges[u].pb(v);
  	edges[v].pb(u);
  }
  dfs(1,0);

  int ans=0;
  
  FOR(i,1,N-1)
  {
  	if(used[i])
  		ans++;
  }

  cout<<max(ans,1)<<endl;


  FOR(i,1,m)
  if(color[i])
  cout<<color[i]<<" ";
  else
  	cout<<1<<" ";
  return 0;
}