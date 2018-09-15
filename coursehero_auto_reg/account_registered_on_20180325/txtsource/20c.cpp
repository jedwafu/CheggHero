#include <bits/stdc++.h>
using namespace std;

#define INF 10000000

typedef long long ll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef map<string, int> msi;

#define all(x) x.begin(), x.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define spresent(c,x) ((c).find(x) != (c).end())  // for set,map
#define present(c,x) (find(all(c),x) != (c).end())  // for vector
#define F first
#define S second
#define loop(i,a,b) for(int i=int(a);i<=int(b);++i)
#define nloop(i,a,b) for(int i= int(a);i>=int(b);--i)

vii edges[100010];

ll dis[100010];
int par[100010]={0};
bool done[100010]={false};

priority_queue<ii> q_dij;

void dijkstra(int source,int dest)
{
	dis[source]=0;
	par[source]=0;
	done[source]=true;
	
	q_dij.push(mp(dis[source],source));
	
	while(q_dij.empty()==false)
	{
		
		int s=q_dij.top().S;
		
		 if(s==dest)
		 return;
		
		 done[s]=true;
		
		 q_dij.pop();
	    
	    
		loop(i,0,sz(edges[s])-1)
		{
			if(!done[edges[s][i].F] && dis[edges[s][i].F]>dis[s]+edges[s][i].S)
			{
				dis[edges[s][i].F]=dis[s]+edges[s][i].S;
				par[edges[s][i].F]=s;
				q_dij.push(mp(-dis[edges[s][i].F],edges[s][i].F));
			}
		}
	}
}

void print_path(int source,int n)
{
	if(n==source)
	cout<<source<<" ";
	
	else if(par[n]==0)
	cout<<-1;
	
	else
	{
	print_path(source,par[n]);
	cout<<n<<" ";
    }
}

int main()
{
	int n,m;
	
	cin>>n>>m;

	loop(i,1,n)
	dis[i]=1e12;
	
	loop(i,1,m)
	{
		int a,b,c;
		cin>>a>>b>>c;
		edges[a].pb(mp(b,c));
		edges[b].pb(mp(a,c));
	}
		
	dijkstra(1,n);
	print_path(1,n);	
}
