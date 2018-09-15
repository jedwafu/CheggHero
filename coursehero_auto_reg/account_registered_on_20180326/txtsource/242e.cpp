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

int n,m;
ll ans;
int lazy[20][4*N];
int tree[20][4*N];

void Update(int cx , int cy , int qx , int qy , int kd , int pos)
{
  if(lazy[kd][pos])
  {
    lazy[kd][pos]=0;
    tree[kd][pos]=(cy-cx+1)-tree[kd][pos];
    if(cx!=cy)
    {
      lazy[kd][pos*2]^=1;
      lazy[kd][pos*2+1]^=1;
    }
  }
  if(cy<qx || qy<cx) return;
  if(qx<=cx && cy<=qy)
  {
    tree[kd][pos]=(cy-cx+1)-tree[kd][pos];
    if(cx!=cy)
    {
      lazy[kd][pos*2]^=1;
      lazy[kd][pos*2+1]^=1;
    }
    return;
  }
  int mid=(cx+cy)>>1;
  Update(cx,mid,qx,qy,kd,pos*2);
  Update(mid+1,cy,qx,qy,kd,pos*2+1);
  tree[kd][pos]=tree[kd][pos*2]+tree[kd][pos*2+1];
}

void Query(int cx , int cy , int qx , int qy , int kd , int pos)
{
  if(lazy[kd][pos])
  {
    lazy[kd][pos]=0;
    tree[kd][pos]=(cy-cx+1)-tree[kd][pos];
    if(cx!=cy)
    {
      lazy[kd][pos*2]^=1;
      lazy[kd][pos*2+1]^=1;
    }
  }
  if(cy<qx || qy<cx) return;
  if(qx<=cx && cy<=qy)
  {
    ans+=(ll)tree[kd][pos]*(ll)(1<<kd);
    return;
  }
  int mid=(cx+cy)>>1;
  Query(cx,mid,qx,qy,kd,pos*2);
  Query(mid+1,cy,qx,qy,kd,pos*2+1);
  tree[kd][pos]=tree[kd][pos*2]+tree[kd][pos*2+1];
}

int main()
{
  cin>>n;
  FOR(i,1,n)
  {
    int x;
    cin>>x;
    for(int j=0 ; j<20 ; j++)
      if(x&(1<<j))
        Update(1,n,i,i,j,1);
  }

  cin>>m;
  while(m--)
  {
    int st,x,y,bm;
    cin>>st>>x>>y;
    if(st==1)
    {
      ans=0;
      for(int i=0 ; i<20 ; i++)
        Query(1,n,x,y,i,1);
      cout<<ans<<endl;
    }

    else
    {
      cin>>bm;
      for(int i=0 ; i<20 ; i++)
        if(bm&(1<<i))
          Update(1,n,x,y,i,1);
    }
  }
  return 0;
}