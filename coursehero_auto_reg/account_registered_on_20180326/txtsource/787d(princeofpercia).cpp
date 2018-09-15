//submitting prince of persia's code to see if it passes the time limit constraints.

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define PB pop_back()
#define iOS ios_base::sync_with_stdio(false)
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define umap unordered_map
#define double long double
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef vector<int> vi;
typedef complex<double> point;
template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
const int maxn = 1e5 + 100;
const ll inf = 1LL << 60;
int ver[2][4 * maxn];	// 0: to [l, r], 1: from [l, r]
vector<pii> adj[9 * maxn];
ll dis[9 * maxn];
bool mark[9 * maxn];
int n, q, s, nx;
priority_queue <pli, vector<pli>, greater<pli>> pq; 
void build(int t, int id = 1, int l = 0, int r = n){
	ver[t][id] = nx ++;
	if(r - l < 2){
		if(!t)
			adj[ver[t][id]].pb({l, 0});
		else
			adj[l].pb({ver[t][id], 0});
		return ;
	}
	int mid = (l + r) >> 1;
	build(t, L(id), l, mid);
	build(t, R(id), mid, r);
	if(!t)
		adj[ver[t][id]].pb({ver[t][L(id)], 0}),
		adj[ver[t][id]].pb({ver[t][R(id)], 0});
	else
		adj[ver[t][L(id)]].pb({ver[t][id], 0}),
		adj[ver[t][R(id)]].pb({ver[t][id], 0});
}
void add(int v, int w, int x, int y, int t, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y)	return ;
	if(x <= l && r <= y){
		if(!t)
			adj[v].pb({ver[t][id], w});
		else
			adj[ver[t][id]].pb({v, w});
		return ;
	}
	int mid = (l + r) >> 1;
	add(v, w, x, y, t, L(id), l, mid);
	add(v, w, x, y, t, R(id), mid, r);
}
int main(){
	scanf("%d %d %d", &n, &q, &s);
	-- s;
	nx = n;
	build(0), build(1);
	while(q--){
		int type;
		scanf("%d", &type);
		if(type == 1){
			int v, u, w;
			scanf("%d %d %d", &v, &u, &w);
			-- v, -- u;
			adj[v].pb({u, w});
		}
		else{
			int v, l, r, w;
			scanf("%d %d %d %d", &v, &l, &r, &w);
			-- v, -- l;
			add(v, w, l, r, type-2);
		}
	}
	fill(dis, dis + 9 * maxn, inf);
	dis[s] = 0;
	pq.push({0LL, s});
	while(!pq.empty()){
		int v = pq.top().y;
		pq.pop();
		if(mark[v])	continue ;
		mark[v] = true;
		rep(p, adj[v]){
			int u = p.x, w = p.y;
			if(dis[u] > dis[v] + w){
				dis[u] = dis[v] + w;
				pq.push({dis[u], u});
			}
		}
	}
	For(i,0,n)
		printf("%lld ", (dis[i] == inf? -1: dis[i]));
	puts("");
	return 0;
}