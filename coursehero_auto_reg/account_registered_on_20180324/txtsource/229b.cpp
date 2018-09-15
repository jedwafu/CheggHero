#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,int> ii;

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
int n,m;
vector<ii> edges[N];
vector<ll> delay[N];

ll dijkstra()
{
	priority_queue<ii, vector<ii>, greater<ii> > Q;
	vector<ll> dist(N, INF); 
	vector<int> dad(N, -1);
	Q.push(make_pair(0, 1));
	dist[1] = 0;
	while (!Q.empty()) {
		ii p = Q.top();
		Q.pop();
		int here = p.second;
		if (here == n) break;
		if (dist[here] != p.first) continue;
        
        FOR(i,0,sz(delay[here])-1)
        {
        	//cout<<"here";
        	if(delay[here][i]==dist[here])
        		dist[here]++;

        	else if(delay[here][i]>dist[here])
        		break;
        }
       // cout<<"distance of "<<here<<" : "<<dist[here]<<endl;
		for (vector<ii>::iterator it = edges[here].begin(); it != edges[here].end(); it++) {
			if (dist[here] + it->first < dist[it->second]) {
				dist[it->second] = dist[here] + it->first;
				dad[it->second] = here;
				Q.push(make_pair(dist[it->second], it->second));
			}
		}
	}
	return dist[n];
}
int main(){
  fast;
  cin>>n>>m;
  FOR(i,1,m)
  {
      int u,v;
      ll c;
      cin>>u>>v>>c;
      edges[u].pb(mp(c,v));
      edges[v].pb(mp(c,u));
  }
  FOR(i,1,n)
  {
  	int k;
  	cin>>k;
  	ll temp;
  	FOR(j,1,k)
    {
    	cin>>temp;
    	delay[i].pb(temp);
    }
  }
  
  ll ans=dijkstra();
  if(ans==INF)
  	cout<<-1;
  else cout<<ans;
  return 0;
}