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

ll arr[N];
vi edges[N];
ll s[4*N];

void build(int curr,int l,int r){
  if(l == r){
    s[curr] = arr[l]+2;
    return;
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  build(c1,l,mid);
  build(c2,mid+1,r);
  s[curr] = max(s[c1],s[c2]);
}

void update(int curr,int l,int r,int index,ll val){
  if(l==r){
      s[curr]=val;
      return ;
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  if(index<=mid)
  update(c1,l,mid,index,val);
  else
  update(c2,mid+1,r,index,val);
  s[curr] = max(s[c1],s[c2]);
}

ll query(int curr,int l,int r,int x,int y){
  if(l > y || r < x)return -INF;
  if(x <= l && r <= y){
    return s[curr];
  }
  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  ll q = max(query(c1,l,mid,x,y),query(c2,mid+1,r,x,y));
  return q;
}

int main(){
  fast;
  int n;
  cin>>n;
  FOR(i,1,n)
  {
  	cin>>arr[i];
  	//val.insert(arr[i]+2);
  }


  FOR(i,1,n-1)
  {
  	int u,v;
  	cin>>u>>v;
  	edges[u].pb(v);
  	edges[v].pb(u);
  }

  ll ans=INF;

  build(1,1,n);
  FOR(i,1,n)
  {
  	update(1,1,n,i,arr[i]);
  	FOR(j,0,sz(edges[i])-1)
  	{
  		update(1,1,n,edges[i][j],arr[edges[i][j]]+1);
  	}

  	ans=min(ans,query(1,1,n,1,n));
	
	update(1,1,n,i,arr[i]+2);
  	FOR(j,0,sz(edges[i])-1)
  	{
  		update(1,1,n,edges[i][j],arr[edges[i][j]]+2);
  	}  	
  }
  cout<<ans;
  return 0;
}