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

ll r[N],h[N];
ii arr[N]; 

ll seg[4*N];

void build(int curr,int l,int r){
  FOR(i,0,4*N-1)
  seg[i]=(ll)0;
}

void update(int curr,int l,int r,int index,ll val){
  if(l==r){
      seg[curr]=val;
      return ;
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  if(index<=mid)
  update(c1,l,mid,index,val);
  else
  update(c2,mid+1,r,index,val);

  seg[curr] = max(seg[c1],seg[c2]);
}

ll query(int curr,int l,int r,int x,int y){
  if(l > y || r < x)return (ll)0;
  if(x <= l && r <= y){
    return seg[curr];
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
  	cin>>r[i]>>h[i];
  	arr[i]=mp(r[i]*r[i]*h[i],-i);
  }

  build(1,1,n);

  sort(arr+1,arr+n+1);

  update(1,1,n,-arr[1].S,arr[1].F);
  
  FOR(i,2,n)
  {
  		ll val=query(1,1,n,1,-arr[i].S-1);
  		val+=arr[i].F;
  		update(1,1,n,-arr[i].S,val);
  }

   ll final=query(1,1,n,1,n);

  double PI=acos(-1);
  cout<<fixed<<setprecision(12)<<PI*final;
  return 0;
}