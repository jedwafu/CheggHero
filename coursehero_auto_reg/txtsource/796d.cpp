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

bool police[N];
bool del[N];
vector<ii> edges[N];
int dist[N];
queue<ii> Q;

int main(){
  fast;
  int n,k,d;
  cin>>n>>k>>d;
  fill(police,0);
  fill(del,0);


  FOR(i,1,n)
  dist[i]=mod;

  FOR(i,1,k)
  {
  	int p;
  	cin>>p;
  	police[p]=true;
  	dist[p]=0;
  }

  FOR(i,1,n-1)
  {
  	int u,v;
  	cin>>u>>v;
  	edges[u].pb(mp(v,i));
  	edges[v].pb(mp(u,i));	
  }

  int ans=0;
  FOR(i,1,n)
  {
  	if(police[i])
  		ans++;
  }

  cout<<ans-1<<endl;

  FOR(i,1,n)
  if(!dist[i])
  	Q.push(mp(i,0));

  while(!Q.empty())
  {
  	int s=Q.front().F;
  	int p=Q.front().S;
  	Q.pop();

  	FOR(i,0,sz(edges[s])-1)
  	{
  		if(edges[s][i].F==p)
  			continue;

  		if(dist[edges[s][i].F]>1+dist[s])
  		{
  			dist[edges[s][i].F]=1+dist[s];
  			Q.push(mp(edges[s][i].F,s));
  		}
  		else
  		{
  			//cout<<"deleting road "<<edges[s][i].S<<" from "<<s<<endl;
  			del[edges[s][i].S]=true;
  		}
  	}
  }

  FOR(i,1,n-1)
  if(del[i])
  	cout<<i<<" ";

  return 0;
}	