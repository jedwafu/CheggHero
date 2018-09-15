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
const int N = 1e6+10; 
string s;

struct node
{
	int len;
	int leftrem;
	int rightrem;
};

node seg[4*N];


void build(int curr,int l,int r)
{
  
  if(l == r)
  {
   	if(s[l]=='(')
   	{
   		seg[curr].len=0;
   		seg[curr].leftrem=1;
   		seg[curr].rightrem=0;
   	}
   	else
   	{
   		seg[curr].len=0;
   		seg[curr].leftrem=0;
   		seg[curr].rightrem=1;
   	}
    return;
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  build(c1,l,mid);
  build(c2,mid+1,r);

  int common=min(seg[c1].leftrem,seg[c2].rightrem);
  
  seg[curr].len = seg[c1].len+seg[c2].len+2*common;
  seg[curr].leftrem=seg[c1].leftrem+seg[c2].leftrem-common;
  seg[curr].rightrem=seg[c1].rightrem+seg[c2].rightrem-common;
  
  //cout<<l<<" "<<r<<" "<<seg[curr].len<<" "<<seg[curr].leftrem<<" "<<seg[curr].rightrem<<endl;
  return;
}

node query(int curr,int l,int r,int x,int y)
{
  if(l > y || r < x)return seg[0];

  if(x <= l && r <= y)
  return seg[curr];
  
  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  
  node q1 = query(c1,l,mid,x,y);
  node q2 = query(c2,mid+1,r,x,y);
  
  node res;

  int common=min(q1.leftrem,q2.rightrem);
  res.len=q1.len+q2.len+2*common;
  res.leftrem=q1.leftrem+q2.leftrem-common;
  res.rightrem=q1.rightrem+q2.rightrem-common;

  return res;
}

int main()
{
  fast;
  int m;
  cin>>s;
  cin>>m;
  int n=sz(s);
  seg[0].len=seg[0].leftrem=seg[0].rightrem=0;
  build(1,0,n-1);

  FOR(i,1,m)
  {
  	int l,r;
  	cin>>l>>r;
  	cout<<query(1,0,n-1,l-1,r-1).len<<endl;
  }
  return 0;
}