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
const int N = 1e5+10; 

const int maxN = 100500;
const int logMaxN = 17;

int n;
vector<vector<int>> e;
int par[logMaxN][maxN];
vector<int> in, out, h;
int timer;

void dfs(int v)
{
    in[v] = timer++;
    for (int u: e[v])
    {
        par[0][u] = v;
        h[u] = h[v] + 1;
        dfs(u);
    }
    out[v] = timer++;
}

bool isPc(int p, int c)
{
    return in[c] >= in[p] && out[c] <= out[p];
}

int lca(int u, int v)
{
    if (isPc(u, v)) return u;
    if (isPc(v, u)) return v;
    
    for (int log = logMaxN - 1; log >= 0; log--)
        if (!isPc(par[log][u], v))
            u = par[log][u];
        
    return par[0][u];
}

int main(){
    fast;
    int q;
    cin>>n>>q;

    e.resize(n);
    in.resize(n);
    out.resize(n);
    h.resize(n);
    
    par[0][0] = 0;
    
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        p--;
        e[p].push_back(i);
    }
    
    dfs(0);
    
    for (int log = 1; log < logMaxN; log++)
        for (int i = 0; i < n; i++)
            par[log][i] = par[log - 1][par[log - 1][i]];

  FOR(i,1,q)
  {
  	int a,b,c;
  	cin>>a>>b>>c;
  	a--;b--;c--;

  	if(a==b and b==c)
  	{
  		cout<<1<<endl;
  		continue;
  	}
  	if(a==b and b!=c)
  	{
  		cout<<h[b]+h[c]-2*h[lca(b,c)]+1<<endl;
  		continue;
  	}
  	if(a==c and a!=b)
  	{
  		cout<<h[b]+h[a]-2*h[lca(b,a)]+1<<endl;
  		continue;	
  	}
  	if(b==c and b!=a)
  	{
  		cout<<h[b]+h[a]-2*h[lca(b,a)]+1<<endl;
  		continue;
  	}

  	int ans1,ans2,ans3;
  	int u1,u2,v1,v2;

  	u1=a;u2=c;v1=b;v2=c;
  	if(h[u1]>h[u2])
  		swap(u1,u2);
  	if(h[v1]>h[v2])
  		swap(v1,v2);
	ans1=max(0,h[lca(u2,v2)]-max(h[v1],h[u1]));

	u1=a;u2=b;v1=c;v2=b;
  	if(h[u1]>h[u2])
  		swap(u1,u2);
  	if(h[v1]>h[v2])
  		swap(v1,v2);
	ans2=max(0,h[lca(u2,v2)]-max(h[v1],h[u1]));

	u1=b;u2=a;v1=c;v2=a;
  	if(h[u1]>h[u2])
  		swap(u1,u2);
  	if(h[v1]>h[v2])
  		swap(v1,v2);
	ans3=max(0,h[lca(u2,v2)]-max(h[v1],h[u1]));
  	
  	cout<<1+max(ans1,max(ans2,ans3))<<endl;
  } 
  return 0;
}