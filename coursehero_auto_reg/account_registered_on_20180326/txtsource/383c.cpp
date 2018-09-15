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
const int N = 2e5+10; 

int a[N];
int s[4*N];
int in[N],out[N],parity[N];
int timer=1;
vi edges[N];

void update(int curr,int l,int r,int left,int right, int val){
  if(left>r or right<l)
  	return ;

  if(l>=left and r<=right)
  {
	  s[curr]+=val;
      return ;
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  update(c1,l,mid,left,right,val);
  update(c2,mid+1,r,left,right,val);
}

int query(int curr,int l,int r,int index){
	
  if(index<l or index > r) 
  	return 0;

  if(l==r){
    return s[curr];
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  return s[curr]+query(c1,l,mid,index)+query(c2,mid+1,r,index);
}

void dfs(int s,int p,int pr)
{
	parity[s]=pr;
	in[s]=timer++;

	FOR(i,0,sz(edges[s])-1)
	{
		if(edges[s][i]==p)
			continue;

		dfs(edges[s][i],s,1-pr);
	}

	out[s]=timer-1;
}

int main(){
  fast;
  int n,m;
  cin>>n>>m;
  FOR(i,1,n)
  cin>>a[i];

  fill(s,0);

  FOR(i,1,n-1)
  {
  	int u,v;
  	cin>>u>>v;
  	edges[u].pb(v);
  	edges[v].pb(u);
  }

  dfs(1,0,1);

  FOR(i,1,m)
  {
  	int type;
  	cin>>type;
  	if(type==1)
  	{
  		int index,val;
  		cin>>index>>val;
  		if(!parity[index])
  			val=-val;
  		update(1,1,n,in[index],out[index],val);
  	}
  	if(type==2)
  	{
  		int index;
  		cin>>index;
  		int q=query(1,1,n,in[index]);
  		if(parity[index])
  			cout<<a[index]+q<<endl;
  		else
  			cout<<a[index]-q<<endl;
  	}

  }
  return 0;
}