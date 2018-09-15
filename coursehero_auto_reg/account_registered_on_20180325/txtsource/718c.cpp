//motivated by code from swastik1996
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
const int mod = 1e9+7;
const int N = 1e5+10; 

struct matrix{
  ll a[2][2];
  matrix(ll v1=1,ll v2=0,ll v3=0,ll v4=1)
  {
    a[0][0]=v1;
    a[0][1]=v2;
    a[1][0]=v3;
    a[1][1]=v4;
  }
};

ll mul(ll a,ll b)
{
  ll temp=(a*b)%mod;
  if(temp<0)
    temp+=mod;
  return temp;
}
ll add(ll a,ll b)
{
  ll temp =(a+b)%mod;
   if(temp<0)
    temp+=mod;
  return temp; 
}

matrix operator * (const matrix &m1,const matrix &m2){
  matrix m;
  m.a[0][0]=add(mul(m1.a[0][0],m2.a[0][0]),mul(m1.a[0][1],m2.a[1][0]));
  m.a[0][1]=add(mul(m1.a[0][0],m2.a[0][1]),mul(m1.a[0][1],m2.a[1][1]));
  m.a[1][0]=add(mul(m1.a[1][0],m2.a[0][0]),mul(m1.a[1][1],m2.a[1][0]));
  m.a[1][1]=add(mul(m1.a[1][0],m2.a[0][1]),mul(m1.a[1][1],m2.a[1][1]));
  return m;
}
matrix operator + (const matrix &m1,const matrix &m2){
  matrix m;
  m.a[0][0]=add(m1.a[0][0],m2.a[0][0]);
  m.a[0][1]=add(m1.a[0][1],m2.a[0][1]);
  m.a[1][0]=add(m1.a[1][0],m2.a[1][0]);
  m.a[1][1]=add(m1.a[1][1],m2.a[1][1]);
  return m;
}
matrix id;
matrix expo(matrix a,ll b){
  if(!b)return id;
  matrix ret = expo(a,b/2);
  ret = ret*ret;
  if(b&1)ret = ret*a;
  return ret;
}


ll A[N];
matrix s[4*N],lazy[4*N];
matrix val;
bool upd[4*N];
matrix fib(1,1,1,0);
void build(int curr,int l,int r){
  upd[curr] = 0;
  lazy[curr]=id;
  if(l == r){
    s[curr] = expo(fib,A[l]);
    return;
  }
  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  build(c1,l,mid);
  build(c2,mid+1,r);
  s[curr] = s[c1] + s[c2];
}
void push(int curr,int l,int r){
  if(upd[curr]){
    s[curr] = s[curr] * lazy[curr];
    if(l != r){
      int c1 = curr<<1,c2 = c1|1;
      upd[c1] = upd[c2] = 1;
      lazy[c1] = lazy[c1] * lazy[curr];
      lazy[c2] = lazy[c2] * lazy[curr];
    }
    upd[curr] = 0;
    lazy[curr]=id; 
  }
}

void update(int curr,int l,int r,int x,int y){
  push(curr,l,r);
  if(l > y || r < x)return;
  if(x <= l && r <= y){
    lazy[curr] = lazy[curr] * val;
    upd[curr] = 1;
    push(curr,l,r);
    return;
  }
  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  update(c1,l,mid,x,y);
  update(c2,mid+1,r,x,y);
  s[curr] = s[c1] + s[c2];
}
ll query(int curr,int l,int r,int x,int y){
  push(curr,l,r);
  if(l > y || r < x)return 0;
  if(x <= l && r <= y){
    return s[curr].a[0][1];
  }
  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  ll q = add(query(c1,l,mid,x,y),query(c2,mid+1,r,x,y));
  return q;
}
int main(){
  fast;
  int n,m;
  cin >> n >> m;
  FOR(i,0,n-1)
  cin >> A[i];
  build(1,0,n-1);
  while(m--){
    int c;
    cin >>c;
    if(c == 1){
      int l,r;
      ll x;
      cin >> l >> r >> x;
      l--,r--;
      val = expo(fib,x);
      update(1,0,n-1,l,r);
    }
    else{
      int l,r;
      cin >> l >> r;
      l--,r--;
      cout << query(1,0,n-1,l,r) << "\n";
    }
  }
  return 0;
}