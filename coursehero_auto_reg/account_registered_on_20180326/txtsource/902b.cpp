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
const int N = 1e4+10; 

vector<int> edges[N];
int col[N];

int ans=0;
void dfs(int s,int p)
{
	if(col[s]!=col[p])
		ans++;

	FOR(i,0,sz(edges[s])-1)
	{
		if(edges[s][i]==p)
			continue;

		dfs(edges[s][i],s);
	}
}

int main(){
  fast;
  int n;
  cin>>n;
  for(int i=2;i<=n;i++)
  {
  	int p;
  	cin>>p;
  	edges[i].push_back(p);
  	edges[p].push_back(i);
  }

  FOR(i,1,n)
  cin>>col[i];
  
  col[0]=0;

  dfs(1,0);
  cout<<ans<<endl;
  return 0;
}