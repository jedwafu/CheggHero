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
const int N = 2e5+10; 

int n,e;
int edges[2][N];
vi edg[N];
stack<ii> nbr[N];
int indeg[N];
int outdeg[N];
bool done[N];
bool donev[N];

void dfs(int source)
{
	bool flag=false;
	ii e;
   while(!nbr[source].empty())
   {
   		e=nbr[source].top();
   		nbr[source].pop();
   		if(!done[e.S])
   		{
   			flag=true;
   			break;
   		}	
   }

   if(flag)
   {
   	//cout<<"edge from"<<source<<" to "<<e.F<<endl;
   	edges[0][e.S]=source;
    edges[1][e.S]=e.F;
    edg[source].pb(e.F);
    done[e.S]=true;
    dfs(e.F);
   }
}

void dfs2(int source)
{
	//cout<<"here at "<<source<<endl;
  donev[source]=true;
  FOR(i,0,sz(edg[source])-1)
  {
  	if(!donev[edg[source][i]])
  		dfs2(edg[source][i]);
  } 
}

int main(){
  fast;
  
  cin>>n>>e;
  fill(done,0);
  FOR(i,1,e)
  {
     cin>>edges[0][i]>>edges[1][i];
     nbr[edges[0][i]].push(mp(edges[1][i],i));
     nbr[edges[1][i]].push(mp(edges[0][i],i));
     indeg[edges[1][i]]++;
     outdeg[edges[0][i]]++;
  }

  FOR(i,1,n)
  {
     if((indeg[i]+outdeg[i])==0 or (indeg[i]+outdeg[i])%2)
     {
     	cout<<"NO";
     	return 0;
     }
  }
  
  FOR(i,1,n)
  dfs(i);
  
  fill(donev,0);
  dfs2(1);

  FOR(i,1,n)
  if(!donev[i])
  {
  	cout<<"NO";
  	return 0;
  }
  
  cout<<"YES"<<endl;
  FOR(i,1,e)
  cout<<edges[0][i]<<" "<<edges[1][i]<<endl;

  return 0;
}