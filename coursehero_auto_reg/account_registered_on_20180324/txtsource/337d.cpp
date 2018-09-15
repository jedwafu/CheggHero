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
const int inf = 1e7;
const ll mod = 1e9+7;
const int N = 1e5+10; 

bool marked[N];
int distup[N];
int distdn[N];
vi edges[N];

void dfsdn(int source,int par)
{
	
	if(marked[source])
		distdn[source]=0;

	FOR(i,0,sz(edges[source])-1)
	{
		if(edges[source][i]==par)
			continue;

		dfsdn(edges[source][i],source);
		if(distdn[edges[source][i]]>-1)
		distdn[source]=max(distdn[source],1+distdn[edges[source][i]]);
	}
}

void dfsup(int source,int par)
{
	int max1=-1,max2=-1;

		FOR(i,0,sz(edges[source])-1)
		{
			if(edges[source][i]==par)
				continue;

			if(distdn[edges[source][i]]>=max1)
			{
				max2=max1;
				max1=distdn[edges[source][i]];
			}
			else if(distdn[edges[source][i]]>=max2)
				max2=distdn[edges[source][i]];
		}
		//cout<<"max1 is "<<max1<<endl;
		//cout<<"max2 is "<<max2<<endl;
		FOR(i,0,sz(edges[source])-1)
		{
			if(edges[source][i]==par)
				continue;

			if(distdn[edges[source][i]]==max1 and max2!=-1)
				distup[edges[source][i]]=max(distup[edges[source][i]],max2+2);
			if(distdn[edges[source][i]]<max1 and max1!=-1)
				distup[edges[source][i]]=max(distup[edges[source][i]],max1+2);

				if(distup[source]!=-1)
				distup[edges[source][i]]=max(distup[edges[source][i]],distup[source]+1);

				if(marked[edges[source][i]])
			distup[edges[source][i]]=max(distup[edges[source][i]],0);
				
				if(marked[source])
				distup[edges[source][i]]=max(distup[edges[source][i]],1);											
		}
	
	

	FOR(i,0,sz(edges[source])-1)
	{
		if(edges[source][i]!=par)
		dfsup(edges[source][i],source);
	}
}
int main(){
  fast;
  int n,m,d;
  cin>>n>>m>>d;
  fill(marked,0);
  fill(distdn,-1);
  fill(distup,-1);

  FOR(i,1,m)
  {	
  	int p;
  	cin>>p;
  	marked[p]=true;
  }

  FOR(i,1,n-1)
  {
  	int u,v;
  	cin>>u>>v;
  	edges[u].pb(v);
  	edges[v].pb(u);
  }

  edges[1].pb(0);
  dfsdn(1,0);
  dfsup(1,0);

  int ans=0;

  FOR(i,1,n)
  if(max(distup[i],distdn[i])<=d)
  	ans++;

  cout<<ans;
  return 0;
}