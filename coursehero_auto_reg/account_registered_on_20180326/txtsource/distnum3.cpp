//Major help for the idea for this problem was taken from :http://codeforces.com/blog/entry/44711#comment-292724
//Some amount of code for LCA and MO's was taken from a link in the comments of the above mentioned blog.

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

int val[N];
int st[N];
int ed[N];
int DP[20][N];
int LVL[N];
int vis[N];
int LCA[N];
int last[N];
int freq[2*N];
vector< pair<int,ii> >queries(N);
vi help;
vi edges[N];
int arr[2*N];
int B[2*N];
int ANS[N];
int cur=0,ans=0;
map<int,int> actual;

struct node{int l,r,t,id;} q[N];int Q1;
struct node2{int x,pre,now;} p[N]; int Q2;
bool cmp(const node &a, const node &b){return B[a.l]<B[b.l] || (B[a.l]==B[b.l] && B[a.r]<B[b.r]) || (B[a.l]==B[b.l] && B[a.r]==B[b.r] && a.t<b.t);}

void dfs(int source,int par)
{
	st[source]=++cur;
	arr[cur]=source;

	for(int i=1;i<20;i++) DP[i][source]=DP[i-1][DP[i-1][source]];
	for(int i=0;i<sz(edges[source]);i++)
	{
		int v=edges[source][i];
		if(v==par)continue;
		LVL[v]=LVL[source]+1;
		DP[0][v]=source;
		dfs(v,source);
	}	
	ed[source]=++cur;
	arr[cur]=source;
}

inline int lca(int u,int v)
{
	if(LVL[u]>LVL[v]) swap(u,v);
	for(int i=19;i>=0;i--)
		if(LVL[v]-(1<<i) >= LVL[u]) v=DP[i][v];
	if(u==v)
		return u;
	for(int i=19;i>=0;i--)
	{
		if(DP[i][u]!= DP[i][v])
		{
			u=DP[i][u];
			v=DP[i][v];
		}
	}
	return DP[0][u];
}

inline void Vis(int x)
{
	if (vis[x]) 
	{
		freq[val[x]]--;
	  //  cout<<"Deleting "<<val[x]<<endl;
		if(freq[val[x]]==0)
		ans--;	
	} 
	else 
	{
		freq[val[x]]++;
		//cout<<"Adding "<<val[x]<<endl;
		if(freq[val[x]]==1)
		ans++;
	}
	vis[x]^=1;
	//cout<<"ans is "<<ans<<endl; 
}
inline void change(int x, int v)
{
	if (vis[x]) Vis(x),val[x]=v,Vis(x); else val[x]=v;
}


void magic(int Q1)
{
	int now=0;
	int curL=1,curR=0;

	
	FOR(i,1,Q1)
	{	
		//cout<<"query is "<<q[i].l<<" "<<q[i].r<<endl;
		while(now<q[i].t) 
		{
			now++;
			change(p[now].x,p[now].now);
		}
		while(q[i].t<now)
		{
			change(p[now].x,p[now].pre);
			now--;
		}
		while(curL<q[i].l)
			Vis(arr[curL++]);
		while(curL>q[i].l)
			Vis(arr[--curL]);
		while(curR<q[i].r)
			Vis(arr[++curR]);
		while(curR>q[i].r)
			Vis(arr[curR--]);

		
		int tans=ans;
		
		if(LCA[q[i].id])
		{
			if(freq[val[LCA[q[i].id]]]+1==1)
				tans++;
		}
		//cout<<"ans for "<<q[i].id<<" "<<tans<<endl;
		ANS[q[i].id]=tans;
	}


}
int main(){
  fast;
  int n,qr;
  cin>>n>>qr;
  actual.clear();
  fill(freq,0);
  fill(vis,0);
  FOR(i,1,n)
  {
  	cin>>val[i];
  	last[i]=val[i];
  	help.pb(val[i]);
  }

  FOR(i,1,n-1)
  {
  	int u,v;
  	cin>>u>>v;
  	edges[u].pb(v);
  	edges[v].pb(u);
  }

  DP[0][1]=1;
  dfs(1,0);

  int Bk=n;
  if (n<=100000) Bk=1750;
  if (n<=90000) Bk=1630;
  if (n<=80000) Bk=1510;
  if (n<=10000) Bk=390;
  FOR(i, 1, cur) B[i]=(i-1)/Bk+1;
  FOR(i,1,qr)
  {
  	int t,u,v;
  	cin>>t>>u>>v;
  	queries[i].F=t;
  	queries[i].S.F=u;
  	queries[i].S.S=v;
  	if(t==2)
  	help.pb(v);
  }

  sort(help.begin(),help.end());
  int lt=1;
  FOR(i,0,sz(help)-1)
  {
  	actual[help[i]]=lt;
  	lt++;
  }

  FOR(i,1,n)
  last[i]=val[i]=actual[val[i]];

  FOR(i,1,qr)
  {
  	int t,u,v;
  	t=queries[i].F;
  	u=queries[i].S.F;
  	v=queries[i].S.S;
  	if(t==1)
  	{	
  		int l=lca(u,v);
  		if(st[u]>st[v]) swap(u,v);
  		++Q1;
  		if(l==u or l==v)
  		{
  			q[Q1]=(node){st[u],st[v],Q2,Q1};
  			LCA[Q1]=(u!=l&&v!=l ? l : 0);
  		}
  		else
  		{
  			q[Q1]=(node){ed[u],st[v],Q2,Q1};
  			LCA[Q1]=(u!=l&&v!=l ? l : 0);
  		}
  	}
  	else
  	{
  		p[++Q2]=(node2){u,last[u],actual[v]};
  		last[u]=actual[v];
  	}
  }

  sort(q+1,q+1+Q1,cmp);
  magic(Q1);
  
  FOR(i,1,Q1)
  cout<<ANS[i]<<endl;
  return 0;
}