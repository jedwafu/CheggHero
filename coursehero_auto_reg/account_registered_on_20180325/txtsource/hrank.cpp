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


ll s[4*N],lazy[4*N];
bool upd[4*N];
void build(int curr,int l,int r){
  upd[curr] = 0;
  lazy[curr] = 
  if(l == r){
    s[curr] = ;
    return;
  }
  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  build(c1,l,mid);
  build(c2,mid+1,r);
  s[curr] = s[c1] + s[c2];
}

void push(int curr,int l,int r){
  if(upd[curr]){
    s[curr] = s[curr] , lazy[curr];
    if(l != r){
      int c1 = curr<<1,c2 = c1|1;
      upd[c1] = upd[c2] = 1;
      lazy[c1] = lazy[c1] , lazy[curr];
      lazy[c2] = lazy[c2] , lazy[curr];
    }
    upd[curr] = 0;
    lazy[id] = 
  }
}

void update(int curr,int l,int r,int x,int y,int val){
  push(curr,l,r);
  if(l > y || r < x)return;
  if(x <= l && r <= y){
    lazy[curr] = lazy[curr] , val;
    upd[curr] = 1;
    push(curr,l,r);
    return;
  }
  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  update(c1,l,mid,x,y);
  update(c2,mid+1,r,x,y);
  s[curr] = s[c1] + s[c2];
}

int query(int curr,int l,int r,int x,int y){
  push(curr,l,r);
  if(l > y || r < x)return 0;
  if(x <= l && r <= y){
    return s[curr].a[0][1];
  }
  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  int q = query(c1,l,mid,x,y) + query(c2,mid+1,r,x,y);
  if(q >= mod)q-=mod;
  return q;
}


int main(){
  fast;
  
  return 0;
}