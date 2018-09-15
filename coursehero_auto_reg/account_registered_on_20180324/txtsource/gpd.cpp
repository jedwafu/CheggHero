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

ll val[N];
vi edges[N];
map<int,int> node;
int cnt=1;

ll dfsmini(int s,int v,ll k,ll ans)
{
	if(s==v)
	{
		ans=min(ans,val[s]^k);
		return ans;
	}

	ans=min(ans,val[s]^k);

	FOR(i,0,sz(edges[s])-1)
	{
		ll val=dfsmini(edges[s][i],v,k,ans);
		if(val!=-1)
			return val;
	}

	return -1;
}

ll dfsmaxi(int s,int v,ll k,ll ans)
{
	if(s==v)
	{
		ans=max(ans,val[s]^k);
		return ans;
	}

	ans=max(ans,val[s]^k);

	FOR(i,0,sz(edges[s])-1)
	{
		ll val=dfsmaxi(edges[s][i],v,k,ans);
		if(val!=-1)
			return val;
	}

	return -1;
}

int main(){
  fast;
  int n,q;
  ll key,r;
  cin>>n>>q>>r>>key;
  
  if(!node[r])
  	node[r]=cnt++;
  val[node[r]]=key;

  FOR(i,1,n-1)
  {
  	ll u,v;
  	ll k;
  	cin>>u>>v>>k;
  	if(!node[u])
  		node[u]=cnt++;
  	if(!node[v])
  		node[v]=cnt++;

  	edges[node[u]].pb(node[v]);
  	val[node[u]]=k;
  }

  ll last_answer=0;

  FOR(i,1,q)
  {
  	int t;
  	cin>>t;
  	t^=last_answer;
  	if(t==0)
  	{
  		ll v,u,k;
  		cin>>v>>u>>k;
  		v^=last_answer;
  		u^=last_answer;
  		k^=last_answer;
  		if(!node[v])
  			node[v]=cnt++;
  		if(!node[u])
  			node[u]=cnt++;
  		edges[node[u]].pb(node[v]);
  		val[node[u]]=k;
  	}
  	else
  	{
  		ll v,k;
  		cin>>v>>k;
  		v^=last_answer;
  		k^=last_answer;

  		ll mini=dfsmini(node[v],node[r],k,INF);
  		ll maxi=dfsmaxi(node[v],node[r],k,0);
  		cout<<mini<<" "<<maxi<<endl;
  		last_answer=mini^maxi;
  	}

  }

  return 0;
}