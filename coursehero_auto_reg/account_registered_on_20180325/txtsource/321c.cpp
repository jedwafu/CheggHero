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

vi edges[N];
int val[N];
void dfs(int source,int par)
{
	val[source]=(((val[par])-1)%26);
	if(val[source]<0)
		val[source]+=26;

	FOR(i,0,sz(edges[source])-1)
	{
		if(edges[source][i]==par)
			continue;
		dfs(edges[source][i],source);
	}
}

int main(){
  fast;
  int n;
  cin>>n;
  FOR(i,1,n-1)
  {
  	int a,b;
  	cin>>a>>b;
  	edges[a].pb(b);
  	edges[b].pb(a);
  }

  val[0]=26;
  dfs(1,0);

  FOR(i,1,n)
  {
  	char ch='A'+val[i];
  	cout<<ch<<" ";
  }
  return 0;
}