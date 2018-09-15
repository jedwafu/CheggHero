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

vector<ii> C;
vector<ii> D;

ll s[4*N];

void build(int curr,int l,int r,int type){
  if(l == r){
    if(type)
    s[curr] = C[l].S;
  else
  s[curr]=D[l].S;
    return;
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  build(c1,l,mid,type);
  build(c2,mid+1,r,type);
  s[curr] = max(s[c1],s[c2]);
}

int query(int curr,int l,int r,int x,int y){
  if(l > y || r < x)return -1;
  if(x <= l && r <= y){
    return s[curr];
  }
  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  int q = max(query(c1,l,mid,x,y),query(c2,mid+1,r,x,y));
  return q;
}

int main(){
  fast;
  int n,c,d;
  cin>>n>>c>>d;
  //fill(dp,-1);
  FOR(i,1,n)
  {
    int b,p;
    char ch;
    cin>>b>>p>>ch;
    if(ch=='C')
    {
      C.pb(mp(p,b));
    }
    if(ch=='D')
    {
      D.pb(mp(p,b));
    }
  }

  sort(C.begin(),C.end());
  sort(D.begin(),D.end());

  if(sz(C)>1)
  build(1,0,sz(C)-1,1);
  int ans=0;

  FOR(i,1,sz(C)-1)
  {
    int rem=c-C[i].F;
    if(rem<C[0].F)
      continue;
    int l=0;
    int r=sz(C)-1;
    int temp;
    while(r-l>1)
    {
      int mid=(l+r)/2;
      if(C[mid].F<=rem)
        l=mid;
      else
        r=mid;
    }
    if(C[r].F<=rem)
      temp=r;
    else 
      temp=l;

    if(temp==i)
    {
      ans=max(ans,C[i].S+query(1,0,sz(C)-1,0,i-1));
    }
    else if(temp>i)
    {
      ans=max(ans,C[i].S+query(1,0,sz(C)-1,0,i-1));
      ans=max(ans,C[i].S+query(1,0,sz(C)-1,i+1,temp));
    }
    else
    ans=max(ans,C[i].S+query(1,0,sz(C)-1,0,temp)); 
  }

  if(sz(D)>1)
  build(1,0,sz(D)-1,0);

  FOR(i,1,sz(D)-1)
  {
    int rem=d-D[i].F;
    if(rem<D[0].F)
      continue;
    int l=0;
    int r=sz(D)-1;
    int temp;
    while(r-l>1)
    {
      int mid=(l+r)/2;
      if(D[mid].F<=rem)
        l=mid;
      else
        r=mid;
    }
    if(D[r].F<=rem)
      temp=r;
    else 
      temp=l;

    if(temp==i)
    {
      ans=max(ans,D[i].S+query(1,0,sz(D)-1,0,i-1));
    }
    else if(temp>i)
    {
      ans=max(ans,D[i].S+query(1,0,sz(D)-1,0,i-1));
      ans=max(ans,D[i].S+query(1,0,sz(D)-1,i+1,temp));
    }
    else
    ans=max(ans,D[i].S+query(1,0,sz(D)-1,0,temp)); 
  }

  int b1=0,b2=0;
  FOR(i,0,sz(C)-1)
  { 
    if(C[i].F<=c)
      b1=max(b1,C[i].S);
  }

  FOR(i,0,sz(D)-1)
  {
    if(D[i].F<=d)
    {
      b2=max(b2,D[i].S);
    }
  }

  if(b1 and b2)
  {
    ans=max(ans,b1+b2);
  }

  cout<<ans<<endl;
  return 0;
}