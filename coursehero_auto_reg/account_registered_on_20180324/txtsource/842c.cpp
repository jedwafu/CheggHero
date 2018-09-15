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
const int N = 2e5+10; 

vi divs[N];
vi edges[N];
int a[N];
int ans[N];
int cnt[N];

void dfs(int s,int p,int cur)
{
	if(p==0)
		ans[s]=a[s];

	FOR(i,0,sz(divs[a[s]])-1)
	cnt[divs[a[s]][i]]++;
	
	
	if(p)
	{
		int maxi=1;
		FOR(i,0,sz(divs[a[s]])-1)
		{
			if(cnt[divs[a[s]][i]]>=cur-1)
				maxi=max(maxi,divs[a[s]][i]);
		}
		FOR(i,0,sz(divs[a[p]])-1)
		{
			if(cnt[divs[a[p]][i]]>=cur-1)
				maxi=max(maxi,divs[a[p]][i]);
		}
		ans[s]=maxi;
	}
	
	FOR(i,0,sz(edges[s])-1)
	{
		if(edges[s][i]==p)
			continue;
		dfs(edges[s][i],s,cur+1);
	}

	FOR(i,0,sz(divs[a[s]])-1)
	cnt[divs[a[s]][i]]--;
}

int main()
{
  fast;
  fill(cnt,0);

  FOR(i,2,N-1)
  {
  	for(int j=i;j<N;j+=i)
  	{
  		divs[j].pb(i);
  	}
  }

  int n;
  cin>>n;
  
  FOR(i,1,n)
  cin>>a[i];
  
  FOR(i,1,n-1)
  {
  	int u,v;
  	cin>>u>>v;

  	edges[u].pb(v);
  	edges[v].pb(u);
  }

  dfs(1,0,1);

  FOR(i,1,n)
  cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}