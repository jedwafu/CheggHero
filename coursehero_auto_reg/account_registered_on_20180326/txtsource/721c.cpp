#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair< pair<int,int>,int> ii;
typedef vector<ii> vii;
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

vector<pair<int,int> > edges[5010];
bool seen[5010][5010];
int  dist[5010][5010];
int  parent[5010][5010];
int  n,m;
priority_queue< ii,vector<ii>,greater<ii> >Q;
vi ans;
void Djikstra(int node)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dist[i][j]=mod,seen[i][j]=false;
    
    dist[1][1]=0;
	Q.push(mp(mp(dist[1][1],1),1));

	while (!Q.empty()) 
	{
		 int u= Q.top().F.S;
         int v= Q.top().S;
		 Q.pop();
		
		if(seen[u][v])
           continue;
        seen[u][v]=true; 

		for(int i=0;i<sz(edges[u]);i++) 
		{   
			if(dist[u][v]>mod)continue;
			if (dist[u][v] + edges[u][i].S < dist[edges[u][i].F][v+1])
			 {
				dist[edges[u][i].F][v+1] = dist[u][v] + edges[u][i].S;
				parent[edges[u][i].F][v+1] = u;
				Q.push(mp(mp(dist[edges[u][i].F][v+1],edges[u][i].F),v+1));
			}
		}
	}
}

int main(){
  fast;
  
  ll T;
  cin>>n>>m>>T;
  
  FOR(i,1,m)
  {
  	int u,v;
  	ll t;
  	cin>>u>>v>>t;
  	edges[u].pb(mp(v,t));
  }
  
  Djikstra(1);
  
  NFOR(i,n,1)
  {
  	if(dist[n][i]>T)continue;

  	int a=n;
  	int b=i;
  	while(a!=1)
  	{
  		ans.pb(a);
  		a=parent[a][b];
  		b--;
  	}
  	break;
  }
  reverse(ans.begin(),ans.end());
  cout<<sz(ans)+1<<endl;
  cout<<1<<" ";
  for(int i=0;i<sz(ans);i++)
  	cout<<ans[i]<<" ";
  

  return 0;
}