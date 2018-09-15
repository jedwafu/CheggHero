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
const int N = 1100000; 

int arr[N];
ll s[4*N];
ll s1[4*N];
bool toggle[50];
ll ansfor[50];
ll alteransfor[50];
ii help[N];

void build(int curr,int l,int r){
  if(l == r)
  {
    s[curr]=0;
    s1[curr]=0;
    return;
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  build(c1,l,mid);
  build(c2,mid+1,r);

  int cnt=0;
  FOR(i,l,mid)
  help[cnt++]=mp(arr[i],1);
  FOR(i,mid+1,r)
  help[cnt++]=mp(arr[i],2);

  sort(help,help+cnt);
  ll tot=0;
  s[curr]=0;
  FOR(i,0,cnt-1)
  {
  	if(help[i].S==1)
  		s[curr]+=tot;
  	else
  	tot++;
  }

  cnt=0;
  FOR(i,l,mid)
  help[cnt++]=mp(arr[i],2);
  FOR(i,mid+1,r)
  help[cnt++]=mp(arr[i],1);

  sort(help,help+cnt);
  tot=0;
  s1[curr]=0;
  FOR(i,0,cnt-1)
  {
  	if(help[i].S==1)
  		s1[curr]+=tot;
  	else
  	tot++;
  }

  return;
}


int main(){
  fast;
  int p;
  scanf("%d",&p);

  int n=pow(2,p);
  FOR(i,1,n)
  scanf("%d",&arr[i]);

  build(1,1,n);
  NFOR(i,p,0)
  {
  	toggle[i]=0;
  	ansfor[i]=0;
  	alteransfor[i]=0;
  	int st=pow(2,p-i);
  	int ed=2*st-1;
  	FOR(j,st,ed)
  	{
  		ansfor[i]+=s[j];
  		alteransfor[i]+=s1[j];
  	}
  }

  int m;
  scanf("%d",&m);
  FOR(k,1,m)
  {
  	int q;
  	scanf("%d",&q);
  	ll ans=0;
  	FOR(i,0,q)
  	toggle[i]=1-toggle[i];
  	FOR(i,0,p)
  	{
  		if(toggle[i])
  			ans+=alteransfor[i];
  		else
  			ans+=ansfor[i];
  	}
  	printf("%lld\n",ans);
  }
  return 0;
}