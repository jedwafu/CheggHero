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

vi edges[N];
int dist[N];
bool vis[N];
int size,maxi;
struct Node
{
    int parent;
    int rank;
    int diam;
};
Node DSU[N];

//Struktura za rad sa disjunktnim skupovima
//Slozenost: Amortizovano O(alfa(N)) po operaciji

inline void MakeSet(int x)
{
    DSU[x].parent = x;
    DSU[x].rank = 1;
    DSU[x].diam = 0; 
}

inline int Find(int x)
{
    if (DSU[x].parent == x) return x;
    DSU[x].parent = Find(DSU[x].parent);
    return DSU[x].parent;
}

inline void Union(int x, int y)
{
    int xRoot = Find(x);
    int yRoot = Find(y);
    if (xRoot == yRoot) return;
    
    if (DSU[xRoot].rank < DSU[yRoot].rank)
    {
        DSU[xRoot].parent = yRoot;
        DSU[yRoot].diam=max(DSU[yRoot].diam,(DSU[xRoot].diam+1)/2+(DSU[yRoot].diam+1)/2+1);
        DSU[yRoot].diam=max(DSU[xRoot].diam,DSU[yRoot].diam);
        DSU[yRoot].rank+=DSU[xRoot].rank;
        //cout<<"Merged "<<xRoot<<" into "<<yRoot<<" with diam "<<DSU[yRoot].diam<<endl;
    }
    else
    {
        DSU[yRoot].parent = xRoot;
        DSU[xRoot].diam=max(DSU[xRoot].diam,(DSU[xRoot].diam+1)/2+(DSU[yRoot].diam+1)/2+1);
        DSU[xRoot].diam=max(DSU[xRoot].diam,DSU[yRoot].diam);
       	DSU[xRoot].rank+=DSU[yRoot].rank;
       // cout<<"Merged "<<yRoot<<" into "<<xRoot<<" with diam "<<DSU[xRoot].diam<<endl;
    }
}

int dfs(int source,int par,int root)
{
	vis[source]=true;
	size++;
	dist[source]=dist[par]+1;
	DSU[source].parent=root;
	int maxi=0,temp;
	FOR(i,0,sz(edges[source])-1)
	{
		if(edges[source][i]==par)
			continue;

		 temp=dfs(edges[source][i],source,root);
		 if(dist[temp]>dist[maxi])
		 	maxi=temp;
	}

	if(dist[maxi]<dist[source])
		return source;

	return maxi;
}

int main(){
  fast;
  int n,m,q;
  scanf("%d %d %d",&n,&m,&q);
  fill(vis,0);
  dist[0]=-1;
  FOR(i,1,m)
  {
  	int a,b;
  	scanf("%d %d",&a,&b);
  	edges[a].pb(b);
  	edges[b].pb(a);
  }

  FOR(i,1,n)
  MakeSet(i);

  FOR(i,1,n)
  {
  	if(!vis[i])
  	{
  		size=0;
  		maxi=dfs(i,0,i);
  		size=0;
  		maxi=dfs(maxi,0,i);
  		//cout<<maxi<<endl;
  		DSU[i].diam=dist[maxi];
  		DSU[i].rank=size;
  		//cout<<"diameter for "<<i<<" is "<<DSU[Find(i)].diam<<endl;
  	}
  }


  FOR(i,1,q)
  {
  	int d;
  	scanf("%d",&d);
  	if(d==1)
  	{
  		int x;
  		scanf("%d",&x);
  		cout<<DSU[Find(x)].diam<<endl;
  	}
  	else
  	{
  		int x,y;
  		scanf("%d %d",&x,&y);
  		Union(x,y);
  	}
  }
  return 0;
}