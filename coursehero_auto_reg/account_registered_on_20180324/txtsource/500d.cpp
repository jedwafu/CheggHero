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

int n;
int length[100010];
ll counts[100010];
ll val[100010];
vii edges[100010];

void new_dfs(int root,int prev)
{
	loop(i,0,sz(edges[root])-1)
    {
    	if(edges[root][i].F==prev) continue;    	
    	
		new_dfs(edges[root][i].F,root);
		counts[root]+=counts[edges[root][i].F];
		
	}
	
	loop(i,0,sz(edges[root])-1)
	{
		if(edges[root][i].F==prev) continue;
		
		val[edges[root][i].S]=counts[edges[root][i].F]*(n-counts[edges[root][i].F]);
	}
	
	
	if(edges[root].size()==1 && edges[root][0].F==prev)
	counts[root]=1;
	   
}

int main()
{
	int q;
	cin>>n;
	loop(i,1,n-1)
	{
		int a,b,l;
		cin>>a>>b>>l;
		edges[a].pb(mp(b,i));
		edges[b].pb(mp(a,i));
		length[i]=l;
		counts[i]=1;
	}
	counts[n]=1;
	
	new_dfs(1,0);
	
	 double sums=0;
	 double factor= 3.0/(((double)n)*(n-1));
	loop(i,1,n-1)
	{
		sums+=2*val[i]*length[i];
	}

	cin>>q;
	
	loop(i,0,q-1)
	{
		int a,b;
		cin>>a>>b;
		sums-=2*val[a]*(length[a]-b);
		length[a]=b;
		printf("%.10lf\n",sums*factor);
	}
	
	return 0;
}
