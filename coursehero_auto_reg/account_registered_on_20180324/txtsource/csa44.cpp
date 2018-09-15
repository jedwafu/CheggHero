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
const int N = 1e5+10; 

vector<ii> edges[N];
bool done[N];
int p[N];
int indx[N];
stack<int> st;
void dfs(int s,int p)
{
	done[s]=true;
	st.push(s);
	FOR(i,0,sz(edges[s])-1)
	{
		if(edges[s][i].S==p or done[edges[s][i].S])
			continue;

		dfs(edges[s][i].S,s);
	}
}
int main()
{
  fast;
  int n,m;
  cin>>n>>m;
  fill(done,0);
  
  while(!st.empty())
  	st.pop();

  FOR(i,1,n)
  {
  	cin>>p[i];
  	indx[p[i]]=i;
  }

  FOR(i,1,m)
  {
  	int a,b;
  	cin>>a>>b;
  	edges[a].pb(mp(indx[b],b));
  	edges[b].pb(mp(indx[a],a));
  }

  FOR(i,1,n)
  sort(edges[i].begin(),edges[i].end());
  
  dfs(1,0);
  int cur=n;
  while(!st.empty())
  {
  	int temp=st.top();
  	st.pop();
  	if(temp!=p[cur])
  	{
  		cout<<0<<endl;
  		return 0;
  	}
  	cur--;
  }
  cout<<1<<endl;
  return 0;
}